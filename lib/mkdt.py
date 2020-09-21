import numpy as np
from random import random
f = open("test.in", "w")
out = ''
b=np.arange(1,10000000,1)
for k in range(5,8):
    a = np.arange(pow(10,k-1), pow(10,k), pow(10,k-1))
    for n in a:
        out += str(n)
        out += '\n'
        c=np.random.choice(b, n, replace=False)
        for r in c:
            rm=int(random()*100)
            out += str(r) + ' ' + str(rm) + '\n'
f.write(out)       
f.close()