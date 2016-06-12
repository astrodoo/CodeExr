import numpy as np
import time
 
my_array = np.arange(1000000, dtype='float64')

t1 = time.time()
my_array_squared = my_array**2.
t2 = time.time()

print 'It took me %0.3e seconds to square the array using Numpy' % (t2-t1)

t1 = time.time()
my_sequence_squared = []
for i in range(1000000):
   my_sequence_squared.append(i**2.)
t2 = time.time()

print 'It took me %0.3e seconds to square the squence without Numpy' % (t2-t1)
