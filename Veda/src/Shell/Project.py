import wx
import sys
from Polygon import *

from xml.dom.minidom import *

class Style:
    brush = [100, 100, 100, wx.SOLID]
    pen = [255, 63, 63, wx.SOLID]
    name = "true"
    
    def __init__(self, name):
        self.name = name
        if(name == "true"):
            self.brush = [127, 127, 127, wx.SOLID]
            self.pen = [255, 63, 63, wx.SOLID, 2]
        elif(name == "false"):
            self.brush = [63, 255, 100, wx.SOLID]
            self.pen = [63, 63, 63, wx.SOLID, 1]                  
        elif(name == "light"):
            self.brush = [100, 100, 100, wx.SOLID]
            self.pen = [255, 63, 63, wx.SOLID, 3]                       
        elif(name == "dark"):
            self.brush = [100, 100, 100, wx.SOLID]
            self.pen = [255, 63, 63, wx.SOLID, 2]                     
        elif(name == "natural"):
            self.brush = [63, 255, 127, wx.SOLID]
            self.pen = [63, 211, 127, wx.SOLID, 2]                        
        elif(name == "toxic"):
            self.brush = [127, 127, 127, wx.SOLID]
            self.pen = [255, 63, 63, wx.SOLID, 2]
        elif(name == "live"):
            self.brush = [100, 100, 100, wx.SOLID]
            self.pen = [255, 63, 63, wx.SOLID, 3]                       
        elif(name == "death"):
            self.brush = [100, 100, 100, wx.SOLID]
            self.pen = [255, 63, 63, wx.SOLID, 2]
    
    def getBrush(self):
        return wx.Brush(wx.Colour(self.brush[0], self.brush[1], self.brush[2]),self.brush[3])
    
    def getPen(self):
        return wx.Pen(wx.Colour(self.pen[0], self.pen[1], self.pen[2]), self.pen[4], self.pen[3])
    
    def getName(self):
        return self.name
    
class Particle:
    id = 0
    x = 0.0
    y = 0.0
    d = 1.0
    
    def __init__(self, x ,y, d):
        self.x = x
        self.y = y
        self.d = d
    
    def setOmg(self):
        pass    
    
    def getPoint(self):
        return self.x, self.y

class Material:
    name = "material"
    id = 0
    
    density = 1.0
    omg = 2.0
    
    d = 4.0
    
    def setInfo(self, name, id):
        self.name = name
        self.id = id
    
    def createParticle(self, x, y, id=0):
        particle = Particle(x, y, self.d)
        particle.id = id
        return particle

class Domen:
    id = 0
    
    polygon = Polygon()
    
    def __init__(self, points, id=0):
        self.polygon = Polygon(points)
    
    def contains(self, point):
        return self.polygon.isInside(point.x, point.y) == 1

class Solid:
    name = "solid"
    id = 0
    
    polygon = Polygon()
    material = Material()
    
    def __init__(self, points):
        self.polygon = Polygon(points)
        
    def fill(self, particles):
        xmin, xmax, ymin, ymax = self.polygon.boundingBox()
        
        d2 = 2 * self.material.d
        x = xmin
        while x < xmax:
            x += d2
            y = ymin
            while y < ymax:
                y += d2
                if self.polygon.isInside(x, y):
                    id = len(particles)
                    particles.append(self.material.createParticle(x, y, id))
                    
        pass
        
    def setInfo(self, name, id):
        self.name = name
        self.id = id
        
    def setMaterial(self, material):
        self.material = material
        
    def scaleIn(self, scale):
        self.polygon.scale(scale, scale, 0.0, 0.0)
        
    def scaleOut(self, scale):
        self.polygon.scale(1.0 / scale, 1.0 / scale, 0.0, 0.0)
        
    def points(self):
        return self.polygon[0]
    
    def len(self):
        return self.polygon.nPoints(0)

class Project:
    name = "Project"
    description = "Calculation project"
    
    materials = []
    solids = []
    particles = []
    
    domens = []
    
    scale = 1.0
    
    styleNormal = Style("true")
    styleSelected = Style("false")
    
    def __init__(self):
        pass
    
    def clear(self):
        self.materials = []
        self.solids = []
        self.particles = []
    
    def addPolygon(self, points):
        del points[-1]
        obj = Solid(points)
        obj.id = len(self.solids)
        obj.scaleIn(self.scale)
        self.solids.append(obj)
        
    def drawTree(self, tree):
        pass
    
    def drawParticles(self, dc):
        dc.BeginDrawing()
        dc.SetPen(wx.BLACK_PEN)
        dc.SetLogicalFunction(wx.COPY)
    
        dc.SetPen(wx.Pen(wx.Colour(100, 100, 100), 1, wx.SOLID))
        
        for part in self.particles:
            x, y = part.getPoint()
            d = part.d
            
            x /= self.scale
            y /= self.scale
            d /= self.scale
            
            dc.DrawCircle(x, y, d * 0.7)
            
        dc.EndDrawing()                
        
    def draw(self, dc):
        dc.BeginDrawing()
        dc.SetPen(wx.BLACK_PEN)
        dc.SetLogicalFunction(wx.COPY)
        
        dc.SetBrush(self.styleNormal.getBrush())
        dc.SetPen(self.styleNormal.getPen())
        
        for obj in self.solids:
            poly = obj
            poly.scaleOut(self.scale)            
            dc.DrawPolygon(obj.points())
            
        dc.EndDrawing()
        
    # generate field
    
    def fillOne(self, ind):
        self.solids[ind].fill(self.particles)
    
    def fill(self):
        for solid in self.solids:
            solid.fill(self.particles)
            
    def clearParticles(self):
        self.particles = []
        
    # common
        
    def addObject(self, obj):
        pass
        
    def getObject(self):
        pass
        
    def addParticle(self, part):
        pass
    
    def getParticle(self):
        pass
    
    # saving, loading
    
    def loadXML(self, fname):
        def getFirst(node, name):
            children = node.getElementsByTagName(name)
            if(children):
                return children[0]
            else:
                return None
            
        def getText(node):
            txt = ""
            for child in node.childNodes:
                if(child.nodeType == child.TEXT_NODE):
                    txt += child.nodeValue
            return txt
        
        def getPoints(node):
            points = []
            point_nodes = solid_node.getElementsByTagName(point_tag)
            
            if(point_nodes):
                for point_node in point_nodes:
                    x = float(point_node.getAttribute("x"))
                    y = float(point_node.getAttribute("y"))
                    points.append([x, y])                        
                
            return points
        
        doc = parse(fname)
        root = getFirst(doc, "root")
        
        # tags
        
        project_tag = Project.__name__.lower()
        solid_tag = Solid.__name__.lower()
        material_tag = Material.__name__.lower()
        point_tag = "point"                 
        
        # load title
        
        title_node = getFirst(root, project_tag)
        self.name = title_node.getAttribute("name")
        self.description = getText(title_node)
        
        
        # load solids
        
        self.solids = []
        solid_nodes = root.getElementsByTagName(solid_tag)
        
        for solid_node in solid_nodes:
            name = solid_node.getAttribute("name")
            id = int(solid_node.getAttribute("id"))
            
            points = getPoints(solid_node)
            
            solid = Solid(points)
            solid.setInfo(name, id)
            self.solids.append(solid)
            
        # load materials
            
        self.materials = []
        material_nodes = root.getElementsByTagName(material_tag)
        
        for material_node in material_nodes:
            name = material_node.getAttribute("name")
            id = int(material_node.getAttribute("id"))
            
            material = Material()
            material.setInfo(name, id)
            
            self.materials.append(material)
        
        
        grid_node = getFirst(root, "grid")
        if(grid_node):
            points = getPoints(domen_node)
                
            self.domens = points
        else:
            print "No grid in file"
             
        area_node = getFirst(root, "area")
        
        if(area_node):
            particle_nodes = area_node.getElementsByTagName("particle")
            if(len(particle_nodes) > 0):
                for particle_node in particle_nodes:
                    id = int(particle_node.getAttribute("id"))
                    
                    x = float(particle_node.getAttribute("x"))
                    y = float(particle_node.getAttribute("y"))
                    
                    d = float(particle_node.getAttribute("d"))
                    
                    particle = Particle(x, y, d)
                    particle.id = id
                    self.particles.append(particle)
        else:
            print "No area in file"
                    
#        except:
#            print "Error load area.\n%s" % (str(sys.exc_info()[1]))
            
    
    def saveXML(self, fname):
        doc = Document()
        
        top = doc.createElement("root")
        doc.appendChild(top)
        
        # tags
        
        project_tag = Project.__name__.lower()
        solid_tag = Solid.__name__.lower()
        material_tag = Material.__name__.lower()
        point_tag = "point"
        
        # save title
        
        title_node = doc.createElement(project_tag)
        title_node.setAttribute("name", self.name)
        title_node.appendChild(doc.createTextNode(self.description))
        top.appendChild(title_node)
        
        # save solids
        
        for obj in self.solids:
            obj_node = doc.createElement(solid_tag)
            obj_node.setAttribute("name", obj.name)
            obj_node.setAttribute("id", "%d" % obj.id)
            obj_node.setAttribute("num", "%d" % obj.len())
        
            for point in obj.points():
                point_node = doc.createElement(point_tag)
                point_node.setAttribute("x", "%f" % point[0])
                point_node.setAttribute("y", "%f" % point[1])
                obj_node.appendChild(point_node)
            
            top.appendChild(obj_node)
            
        # save materials
            
        for mat in self.materials:
            mat_node = doc.createElement(material_tag)
            mat_node.setAttribute("name", mat.name)
            mat_node.setAttribute("id", mat.id)
            
        if(self.domens):
            grid_node = doc.createElement("grid")
            top.appendChild(grid_node)
            for point in self.domens:
                point_node = doc.createElement(point_tag)
                point_node.setAttribute("x", "%f" % point[0])
                point_node.setAttribute("y", "%f" % point[1])
                obj_node.appendChild(point_node)
        
        if(self.particles):
            area_node = doc.createElement("area")
            top.appendChild(area_node)
            for particle in self.particles:
                particle_node = doc.createElement("particle")
                particle_node.setAttribute("id", str(particle.id))
                particle_node.setAttribute("x", str(particle.x))
                particle_node.setAttribute("y", str(particle.y))
                particle_node.setAttribute("d", str(particle.d))
                area_node.appendChild(particle_node)
                
        file = open(fname, "w")
        file.write(doc.toprettyxml())
        file.close()
    
    

