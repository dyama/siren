#!/usr/bin/env siren

a = box [10, 10, 10]
b = box [10, 10, 10]
a = translate a, [5, 5, 5]
c = fuse a, b
brepsave "C:/myfile.brep", c

