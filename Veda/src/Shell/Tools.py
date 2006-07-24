import wx

from Project import *
from Polygon import *

class Tool:
    kDrawing = False
    
    project = None
    dc = None
    
    startPt = wx.Point(0, 0)
    lastPt = wx.Point(0, 0)
    endPt = wx.Point(0, 0)
    
    points = []
    
    def __init__(self, project):
        self.project = project
    
    def setDC(self, dc):
        self.dc = dc
    
    def beginDraw(self, point):
        self.kDrawing = True
        self.points = []
    
    def beginPoint(self, point):
        if(not self.kDrawing):
            self.beginDraw(point)
            
        self._drawAllInvert()
        self.points.append(point)
        self._drawAllInvert()
        
        self.startPt = point
        self.lastPt = point
        
    def endPoint(self, point):
        if(self.kDrawing):
            self._drawInvert(self.startPt, self.lastPt)
    
    def endDraw(self, point):
        self.endPoint(point)
        
        self._drawAllInvert()
        self.points.append(self.points[0])
        self._drawAllInvert()
        
        self.kDrawing = False
        
        self.project.addPolygon(self.points)
        self.project.draw(self.dc)
        
    def _drawAllInvert(self):
        for i in xrange(1, len(self.points)):
            self._drawInvert(self.points[i-1], self.points[i])
        
    def _drawInvert(self, point1, point2):
        self.dc.BeginDrawing()
        self.dc.SetPen(wx.BLACK_PEN)
        self.dc.SetLogicalFunction(wx.INVERT)
        self.dc.DrawLine(point1.x, point1.y, point2.x, point2.y)           
        self.dc.EndDrawing()               
    
    def mediateDraw(self, point):
        if(self.kDrawing):
            self._drawInvert(self.startPt, self.lastPt)
            self._drawInvert(self.startPt, point)
            self.lastPt = point

    
class ToolSelection(Tool):
    def __init__(self):
        pass
    
class ToolLine(Tool):
    def __init__(self):
        pass
    
    def beginDraw(self):
        pass
    
    def endDraw(self):
        pass
    
    def beginPoint(self):
        pass

    def endPoint(self):
        pass
    
class ToolPolygon(Tool):
    def __init__(self):
        pass
    
    def beginDraw(self):
        pass
    
    def endDraw(self):
        pass
    
    def beginPoint(self):
        pass

    def endPoint(self):
        pass        
