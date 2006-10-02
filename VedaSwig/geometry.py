# This file was created automatically by SWIG.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.
import _geometry
def _swig_setattr(self,class_type,name,value):
    if (name == "this"):
        if isinstance(value, class_type):
            self.__dict__[name] = value.this
            if hasattr(value,"thisown"): self.__dict__["thisown"] = value.thisown
            del value.thisown
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    self.__dict__[name] = value

def _swig_getattr(self,class_type,name):
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

import types
try:
    _object = types.ObjectType
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0


class Point(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Point, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Point, name)
    __swig_setmethods__["x"] = _geometry.Point_x_set
    __swig_getmethods__["x"] = _geometry.Point_x_get
    if _newclass:x = property(_geometry.Point_x_get,_geometry.Point_x_set)
    __swig_setmethods__["y"] = _geometry.Point_y_set
    __swig_getmethods__["y"] = _geometry.Point_y_get
    if _newclass:y = property(_geometry.Point_y_get,_geometry.Point_y_set)
    def __init__(self,*args):
        _swig_setattr(self, Point, 'this', apply(_geometry.new_Point,args))
        _swig_setattr(self, Point, 'thisown', 1)
    def __del__(self, destroy= _geometry.delete_Point):
        try:
            if self.thisown: destroy(self)
        except: pass
    def makeRandom(*args): return apply(_geometry.Point_makeRandom,args)
    def makeNaN(*args): return apply(_geometry.Point_makeNaN,args)
    def makeInf(*args): return apply(_geometry.Point_makeInf,args)
    def valid(*args): return apply(_geometry.Point_valid,args)
    def __iadd__(*args): return apply(_geometry.Point___iadd__,args)
    def __isub__(*args): return apply(_geometry.Point___isub__,args)
    def __imul__(*args): return apply(_geometry.Point___imul__,args)
    def __idiv__(*args): return apply(_geometry.Point___idiv__,args)
    def __neg__(*args): return apply(_geometry.Point___neg__,args)
    def __add__(*args): return apply(_geometry.Point___add__,args)
    def __mul__(*args): return apply(_geometry.Point___mul__,args)
    def __div__(*args): return apply(_geometry.Point___div__,args)
    def __and__(*args): return apply(_geometry.Point___and__,args)
    def __xor__(*args): return apply(_geometry.Point___xor__,args)
    def modulus(*args): return apply(_geometry.Point_modulus,args)
    def manhat(*args): return apply(_geometry.Point_manhat,args)
    def modulusTo(*args): return apply(_geometry.Point_modulusTo,args)
    def manhatTo(*args): return apply(_geometry.Point_manhatTo,args)
    def distance(*args): return apply(_geometry.Point_distance,args)
    def turn(*args): return apply(_geometry.Point_turn,args)
    def turn_(*args): return apply(_geometry.Point_turn_,args)
    def turned(*args): return apply(_geometry.Point_turned,args)
    def turned_(*args): return apply(_geometry.Point_turned_,args)
    def normalize(*args): return apply(_geometry.Point_normalize,args)
    def normalized(*args): return apply(_geometry.Point_normalized,args)
    def __str__(*args): return apply(_geometry.Point___str__,args)
    def __repr__(self):
        return "<C Point instance at %s>" % (self.this,)

class PointPtr(Point):
    def __init__(self,this):
        _swig_setattr(self, Point, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Point, 'thisown', 0)
        _swig_setattr(self, Point,self.__class__,Point)
_geometry.Point_swigregister(PointPtr)

class Line(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Line, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Line, name)
    def __init__(self,*args):
        _swig_setattr(self, Line, 'this', apply(_geometry.new_Line,args))
        _swig_setattr(self, Line, 'thisown', 1)
    def __del__(self, destroy= _geometry.delete_Line):
        try:
            if self.thisown: destroy(self)
        except: pass
    def getA(*args): return apply(_geometry.Line_getA,args)
    def getB(*args): return apply(_geometry.Line_getB,args)
    def setA(*args): return apply(_geometry.Line_setA,args)
    def setB(*args): return apply(_geometry.Line_setB,args)
    def length(*args): return apply(_geometry.Line_length,args)
    def distance(*args): return apply(_geometry.Line_distance,args)
    def getNormal(*args): return apply(_geometry.Line_getNormal,args)
    def cross(*args): return apply(_geometry.Line_cross,args)
    def crossIn(*args): return apply(_geometry.Line_crossIn,args)
    def oneSide(*args): return apply(_geometry.Line_oneSide,args)
    def __repr__(self):
        return "<C Line instance at %s>" % (self.this,)

class LinePtr(Line):
    def __init__(self,this):
        _swig_setattr(self, Line, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Line, 'thisown', 0)
        _swig_setattr(self, Line,self.__class__,Line)
_geometry.Line_swigregister(LinePtr)

class Polygon(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Polygon, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Polygon, name)
    def __init__(self,*args):
        _swig_setattr(self, Polygon, 'this', apply(_geometry.new_Polygon,args))
        _swig_setattr(self, Polygon, 'thisown', 1)
    def __del__(self, destroy= _geometry.delete_Polygon):
        try:
            if self.thisown: destroy(self)
        except: pass
    def __lshift__(*args): return apply(_geometry.Polygon___lshift__,args)
    def size(*args): return apply(_geometry.Polygon_size,args)
    def getNum(*args): return apply(_geometry.Polygon_getNum,args)
    def side(*args): return apply(_geometry.Polygon_side,args)
    def add(*args): return apply(_geometry.Polygon_add,args)
    def clear(*args): return apply(_geometry.Polygon_clear,args)
    def square(*args): return apply(_geometry.Polygon_square,args)
    def calcCenter(*args): return apply(_geometry.Polygon_calcCenter,args)
    def calcedCenter(*args): return apply(_geometry.Polygon_calcedCenter,args)
    def getCenter(*args): return apply(_geometry.Polygon_getCenter,args)
    def setCenter(*args): return apply(_geometry.Polygon_setCenter,args)
    def averageRadius(*args): return apply(_geometry.Polygon_averageRadius,args)
    def maxRadius(*args): return apply(_geometry.Polygon_maxRadius,args)
    def minRadius(*args): return apply(_geometry.Polygon_minRadius,args)
    def maxManhatRadius(*args): return apply(_geometry.Polygon_maxManhatRadius,args)
    def minManhatRadius(*args): return apply(_geometry.Polygon_minManhatRadius,args)
    def area(*args): return apply(_geometry.Polygon_area,args)
    def cutWith(*args): return apply(_geometry.Polygon_cutWith,args)
    def cache(*args): return apply(_geometry.Polygon_cache,args)
    def nearSide(*args): return apply(_geometry.Polygon_nearSide,args)
    def contains(*args): return apply(_geometry.Polygon_contains,args)
    def nearOutside(*args): return apply(_geometry.Polygon_nearOutside,args)
    def nearInside(*args): return apply(_geometry.Polygon_nearInside,args)
    def __repr__(self):
        return "<C Polygon instance at %s>" % (self.this,)

class PolygonPtr(Polygon):
    def __init__(self,this):
        _swig_setattr(self, Polygon, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Polygon, 'thisown', 0)
        _swig_setattr(self, Polygon,self.__class__,Polygon)
_geometry.Polygon_swigregister(PolygonPtr)

class Archive(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Archive, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Archive, name)
    def __init__(self,*args):
        _swig_setattr(self, Archive, 'this', apply(_geometry.new_Archive,args))
        _swig_setattr(self, Archive, 'thisown', 1)
    def __del__(self, destroy= _geometry.delete_Archive):
        try:
            if self.thisown: destroy(self)
        except: pass
    def open(*args): return apply(_geometry.Archive_open,args)
    def close(*args): return apply(_geometry.Archive_close,args)
    def get_Version(*args): return apply(_geometry.Archive_get_Version,args)
    def set_Vesion(*args): return apply(_geometry.Archive_set_Vesion,args)
    def __repr__(self):
        return "<C Archive instance at %s>" % (self.this,)

class ArchivePtr(Archive):
    def __init__(self,this):
        _swig_setattr(self, Archive, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Archive, 'thisown', 0)
        _swig_setattr(self, Archive,self.__class__,Archive)
_geometry.Archive_swigregister(ArchivePtr)

class XmlArchive(Archive):
    __swig_setmethods__ = {}
    for _s in [Archive]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, XmlArchive, name, value)
    __swig_getmethods__ = {}
    for _s in [Archive]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, XmlArchive, name)
    def __init__(self,*args):
        _swig_setattr(self, XmlArchive, 'this', apply(_geometry.new_XmlArchive,args))
        _swig_setattr(self, XmlArchive, 'thisown', 1)
    def __del__(self, destroy= _geometry.delete_XmlArchive):
        try:
            if self.thisown: destroy(self)
        except: pass
    def open(*args): return apply(_geometry.XmlArchive_open,args)
    def close(*args): return apply(_geometry.XmlArchive_close,args)
    def __repr__(self):
        return "<C XmlArchive instance at %s>" % (self.this,)

class XmlArchivePtr(XmlArchive):
    def __init__(self,this):
        _swig_setattr(self, XmlArchive, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, XmlArchive, 'thisown', 0)
        _swig_setattr(self, XmlArchive,self.__class__,XmlArchive)
_geometry.XmlArchive_swigregister(XmlArchivePtr)
nvp = _geometry.nvp


class IXmlArchive(XmlArchive):
    __swig_setmethods__ = {}
    for _s in [XmlArchive]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, IXmlArchive, name, value)
    __swig_getmethods__ = {}
    for _s in [XmlArchive]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, IXmlArchive, name)
    def __init__(self,*args):
        _swig_setattr(self, IXmlArchive, 'this', apply(_geometry.new_IXmlArchive,args))
        _swig_setattr(self, IXmlArchive, 'thisown', 1)
    def __del__(self, destroy= _geometry.delete_IXmlArchive):
        try:
            if self.thisown: destroy(self)
        except: pass
    def open(*args): return apply(_geometry.IXmlArchive_open,args)
    def close(*args): return apply(_geometry.IXmlArchive_close,args)
    def __and__(*args): return apply(_geometry.IXmlArchive___and__,args)
    def __repr__(self):
        return "<C IXmlArchive instance at %s>" % (self.this,)

class IXmlArchivePtr(IXmlArchive):
    def __init__(self,this):
        _swig_setattr(self, IXmlArchive, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, IXmlArchive, 'thisown', 0)
        _swig_setattr(self, IXmlArchive,self.__class__,IXmlArchive)
_geometry.IXmlArchive_swigregister(IXmlArchivePtr)

class OXmlArchive(XmlArchive):
    __swig_setmethods__ = {}
    for _s in [XmlArchive]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, OXmlArchive, name, value)
    __swig_getmethods__ = {}
    for _s in [XmlArchive]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, OXmlArchive, name)
    def __init__(self,*args):
        _swig_setattr(self, OXmlArchive, 'this', apply(_geometry.new_OXmlArchive,args))
        _swig_setattr(self, OXmlArchive, 'thisown', 1)
    def __del__(self, destroy= _geometry.delete_OXmlArchive):
        try:
            if self.thisown: destroy(self)
        except: pass
    def open(*args): return apply(_geometry.OXmlArchive_open,args)
    def close(*args): return apply(_geometry.OXmlArchive_close,args)
    def __and__(*args): return apply(_geometry.OXmlArchive___and__,args)
    def __repr__(self):
        return "<C OXmlArchive instance at %s>" % (self.this,)

class OXmlArchivePtr(OXmlArchive):
    def __init__(self,this):
        _swig_setattr(self, OXmlArchive, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, OXmlArchive, 'thisown', 0)
        _swig_setattr(self, OXmlArchive,self.__class__,OXmlArchive)
_geometry.OXmlArchive_swigregister(OXmlArchivePtr)


