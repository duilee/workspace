# Abstractions


full_roster = {
    "Manny Machado" : "Dodgers",
    "Yasiel Puig" : "Dodgers",
    "Aaron Judge" : "Yankees",
    "Clayton Kershaw" : "Dodgers",
    "Giancarlo Stanton" : "Yankees"
}

full_stats = {
    "Manny Machado": ["SO", "1B", "3B", "SO", "HR"],
    "Yasiel Puig": ["3B", "3B", "1B", "1B", "SO"],
    "Aaron Judge": ["SO", "HR", "HR", "1B", "SO"],
    "Clayton Kershaw": ["1B", "SO", "SO", "1B", "SO"],
    "Giancarlo Stanton": ["HR", "SO", "3B", "SO", "2B"],
}

def get_team(player):
    """Returns team that the provided player is a member of.

    >>> get_team("Manny Machado")
    'Dodgers'
    >>> get_team("Aaron Judge")
    'Yankees'
    """
    return full_roster[player]

def get_stats(player):
    """Returns the statistics associated with the provided player.
    >>> get_stats("Manny Machado")
    ['SO', '1B', '3B', 'SO', 'HR']
    >>> get_stats('Aaron Judge')
    ['SO', 'HR', 'HR', '1B', 'SO']
    """
    return full_stats[player]



# Dictionaries

def get_players(team):
    """Returns a list of all players who are members of the given team.

    >>> get_players("Dodgers")
    ['Manny Machado', 'Yasiel Puig', 'Clayton Kershaw']
    >>> get_players("Yankees")
    ['Aaron Judge', 'Giancarlo Stanton']
    """
    lst = []
    for i in full_roster:
        if full_roster[i] == team:
            lst += [i]
    return lst


def common_players(roster):
    """Returns a dictionary containing values along with a corresponding
    list of keys that had that value from the original dictionary.

    >>> common_players(full_roster)
    {'Dodgers': ['Manny Machado', 'Yasiel Puig', 'Clayton Kershaw'], 'Yankees': ['Aaron Judge', 'Giancarlo Stanton']}
    >>> full_roster = {"bob": "excellent", "barnum": "passing", "beatrice": "satisfactory", "bernice": "passing", "ben": "no pass", "belle": "excellent", "bill": "passing", "bernie": "passing", "baxter": "excellent"}
    >>> common_players(full_roster)
    {'excellent': ['bob', 'belle', 'baxter'], 'passing': ['barnum', 'bernice', 'bill', 'bernie'], 'satisfactory': ['beatrice'], 'no pass': ['ben']}
    """
    dic = {}
    for i in roster:
        if roster[i] not in dic:
            dic[roster[i]] = [x for x in roster if roster[x] == roster[i]]


    return dic


# Back to Abstractions!

# Following Functions have been given to you, do NOT modify

def calculate_batting_average(stats):
    hits = 0
    total_bats = 0
    for at_bat in stats:
        if at_bat != "SO":
            hits += 1
        total_bats += 1
    return float(round(hits/total_bats, 1))

def calculate_slugging_percent(stats):
    bases = 0
    total_bats = 0
    for at_bat in stats:
        if at_bat == "1B":
            bases += 1
        elif at_bat == "2B":
            bases += 2
        elif at_bat == "3B":
            bases += 3
        elif at_bat == "HR":
            bases += 4
        total_bats += 1
    return float(round(bases/total_bats, 1))

# Modify Functions below

def calculate_team_BA(team):
    """Given a single team name, returns the mean batting average of all players on that team. You are encouraged to use previous functions that you've defined already
    >>> calculate_team_BA('Dodgers')
    0.6
    >>> calculate_team_BA('Yankees')
    0.6
    """
    rst = common_players(full_roster)
    x = [calculate_batting_average(get_stats(i)) for i in rst[team]]

    return sum(x) / len(x)

def calculate_all_team_SP():
    """Returns a dictionary mapping every team to the average slugging percentage of all players on that team. You are encouraged to use previous functions that you've defined already.
    >>> calculate_all_team_SP()
    {'Dodgers': 1.2, 'Yankees': 1.8}
    """
    rst = common_players(full_roster)
    for i in rst:
        x = [calculate_slugging_percent(get_stats(x)) for x in rst[i]]
        rst[i] = sum(x) / len(x)

    return rst 


