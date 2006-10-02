from geometry import *

p1 = Point(2, 3)
p2 = Point(5, 1)
p3 = Point(6, 7)
p4 = Point(4, 2)
p5 = Point(7, 2)

print p1, p2

line1 = Line(p1, p2)
line2 = Line(p2, p1)

oar = OXmlArchive()

poly = Polygon()
poly << p1 << p2 << p3 << p4 << p5

print "Test xml archiving"

oar.open()
oar & nvp("PointA", p1) & nvp("PointB", p2)
oar & nvp("LineNumberOne", line1)
oar & nvp("LineNumberTwo", line2)
oar & nvp("Palegon", poly)
oar.close()
