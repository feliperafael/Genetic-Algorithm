import pandas as pd
import numpy as np
from math import *
def funcao(x):
	return ((x+5)*(x+5))


data = []

for i in np.arange(-5,5,0.25):
	data.append([i,funcao(i)])

df = pd.DataFrame(data)
print df

df.to_csv("database.dat",sep='\t',index=False,header=False)
