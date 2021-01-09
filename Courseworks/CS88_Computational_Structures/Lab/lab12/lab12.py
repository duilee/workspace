#############
# Models as HOFs #
#############

# Q1
def polynomial(degree, coeffs):
    """
    >>> fourth = polynomial(4, [3,6,2,1, 100])
    >>> fourth(3)   # 3*(3**4) + 6*(3**3) + 2*(3**2) + 1*(3**1) + 100
    526
    >>> third = polynomial(3, [2, 0, 0, 0])
    >>> third(4)   # 2*(4**3) + 0*(4**2) + 0*(4**1) + 0
    128
    """
    def poly(x):
    	sum = 0
    	for i in range(degree + 1):
    		sum += (x**i * coeffs[-(i+1)])
    	return sum
    return poly
    


# Q2
def mean(x):
	"""
	Return the mean of x, where x is a list of data points. 

	"""
	return sum(x) / len(x)

def testmean():
	assert mean([0,0,0,0,0]) == 0, "please pass me!"
	assert mean([1,2,3,4,5]) == 3, "ahhhhh"
	assert mean([1,2,1,2,1.5]) == 1.5, "ahhhh"

def sd(x):
	"""
	Return the standard deviation of x, where x is a list of data points. 

	"""
	sum = 0 
	for i in x:
		sum = sum + (i - mean(x))**2

	return (sum / len(x))**(1/2)

def testsd():
	assert sd([0,0,0,0,0]) == 0, "pass me please!"

	assert int(sd([10, 15, 19, 35, 27, 44])) == 11, "ahhhhh incorrect"

	assert int(sd([10, 15, 7, 13])) == 3, "ahhhh again"


def standard_units(x):
	"""
	Return the standard units of x, where x is a list of data points. 
	"""
	
	return [(i - mean(x)) / sd(x) for i in x]

def testsu():
	"""***PUT YOUR TEST HERE***"""
	assert int(standard_units([1,2,3,4,5])[4]) == 1, "ahhh again"
	assert int(standard_units([2,3,10,15,17])[4]) == 1, "ahhh fix it"
	assert int(standard_units([0,1,1,1,300])[2]) == 0, "ahhh no"

def corr_coeff(x, y):
	"""
	Return the correlation coefficients (r) of x and y, where x is a list of
	data points and y is a list of data points corresponding to x. 

	"""
	sum = 0
	for i in range(len(x)):
		sum = sum + (standard_units(x)[i] * standard_units(y)[i])
	return sum / len(x)

def testcorr_coeff():
	"""***PUT YOUR TEST HERE***"""
	assert round(corr_coeff([1,2,4,5], [1,3,5,7])) == 1, "ahhh error"
	



def regression(points):
    """
    Return a function that takes in x and predicts y, based on a linear regression model. 
    
    >>> tempVIcecream = [[35,1], [33,2], [37,3], [45,5],[47,6],[42,8],[43,9],[51,10]]
    >>> predictor = regression(tempVIcecream)
    >>> predictor(62)    # Round to the third decimal place
    14.597
    """
    def predict(p):
    	x = [x[0] for x in points]
    	y = [x[1] for x in points]
    	slope = corr_coeff(x,y) * sd(y) / sd(x)
    	intercept = mean(y) - (slope * mean(x))
    	return round(slope*p + intercept, 3)
    
    return predict

def testregression():
	tempVIcecream = [[35,1], [33,2], [37,3], [45,5],[47,6],[42,8],[43,9],[51,10]]
	predictor = regression(tempVIcecream)
	assert predictor(62) == 14.597, "ahhh again"
