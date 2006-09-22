from geometry import *

p1 = Point(0, 1)

p2 = Point(2, 3)

print p1
print p2

oar = OXmlArchive()

dx = 3.14
ix = 314

print "\nNext test\n"

omg  = Omg(10)

omg += 4.2
omg += 3
omg += 3.0

print omg

omg *= 3.1

print "\nNext test\n"

print omg

amg = Omg(100)

print omg
print "\nAdding..\n"

omg += amg

print omg

print "\nTest conflicting.."

omg.val = 4
amg.val = 1

print omg
print amg

print "\nArchiving..\n"

oar.open()
oar & p1
oar.close()


