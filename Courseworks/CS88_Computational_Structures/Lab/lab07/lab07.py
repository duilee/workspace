## Abstract Data Types

def make_city(name, lat, lon):
    """
    >>> city = make_city('Berkeley', 0, 1)
    >>> get_name(city)
    'Berkeley'
    >>> get_lat(city)
    0
    >>> get_lon(city)
    1
    """
    return [name, lat, lon]

def get_name(city):
    """
    >>> city = make_city('Berkeley', 0, 1)
    >>> get_name(city)
    'Berkeley'
    """
    return city[0]

def get_lat(city):
    """
    >>> city = make_city('Berkeley', 0, 1)
    >>> get_lat(city)
    0
    """
    return city[1]

def get_lon(city):
    """
    >>> city = make_city('Berkeley', 0, 1)
    >>> get_lon(city)
    1
    """
    return city[2]

from math import sqrt
def distance(city_1, city_2):
    """
    >>> city1 = make_city('city1', 0, 1)
    >>> city2 = make_city('city2', 0, 2)
    >>> distance(city1, city2)
    1.0
    """
    
    return ((get_lat(city_1) - get_lat(city_2))**2 + (get_lon(city_1) - get_lon(city_2))**2)**(1/2)

def closer_city(lat, lon, city1, city2):
    """ Returns the name of either city1 or city2, whichever is closest
        to coordinate (lat, lon).

        >>> berkeley = make_city('Berkeley', 37.87, 112.26)
        >>> stanford = make_city('Stanford', 34.05, 118.25)
        >>> closer_city(38.33, 121.44, berkeley, stanford)
        'Stanford'
        >>> bucharest = make_city('Bucharest', 44.43, 26.10)
        >>> vienna = make_city('Vienna', 48.20, 16.37)
        >>> closer_city(41.29, 174.78, bucharest, vienna)
        'Bucharest'
    """
    city3 = make_city('city3', lat, lon)
    if distance(city1, city3) < distance(city2, city3):
        return get_name(city1)
    else:
        return get_name(city2)


## Dictionaries

def counter(message):
    """ Returns a dictionary of each word in message mapped
    to the number of times it appears in the input string.

    >>> x = counter('to be or not to be')
    >>> x['to']
    2
    >>> x['be']
    2
    >>> x['not']
    1
    >>> y = counter('run forrest run')
    >>> y['run']
    2
    >>> y['forrest']
    1
    """
    word_list = message.split()
    dict = {}
    for i in word_list:
        if i not in dict:
            count = 0
            for x in word_list:
                if i == x:
                    count += 1
            dict[i] = count
    return dict


def replace_all(d, x, y):
    """
    >>> d = {'foo': 2, 'bar': 3, 'garply': 3, 'xyzzy': 99}
    >>> e = replace_all(d, 3, 'poof')

    >>> e == {'foo': 2, 'bar': 'poof', 'garply': 'poof', 'xyzzy': 99}
    True
    """
    for i in d:
        if d[i] == x:
            d[i] = y
    return d



def make_politician(name, party, age):
    """
    >>> woodrow = make_politician('Woodrow Wilson', 'Democrat', 57)
    >>> isinstance(woodrow, dict)
    True
    """
    # Make sure you use a dictionary in your implementation!
    
    return { 
        'name': name,
        'party': party,
        'age': age}

def get_pol_name(politician):
    """
    >>> woodrow = make_politician('Woodrow Wilson', 'Democrat', 57)
    >>> get_pol_name(woodrow)
    'Woodrow Wilson'
    """
    
    return politician['name']

def get_party(politician):
    """
    >>> woodrow = make_politician('Woodrow Wilson', 'Democrat', 57)
    >>> get_party(woodrow)
    'Democrat'
    """

    return politician['party']

def get_age(politician):
    """
    >>> woodrow = make_politician('Woodrow Wilson', 'Democrat', 57)
    >>> get_age(woodrow)
    57
    """
 
    return politician['age']


