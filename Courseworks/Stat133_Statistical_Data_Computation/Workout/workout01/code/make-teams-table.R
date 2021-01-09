# ===================================================================
# Title: Stat133-workout1
# Description: Data perpartion for workout1
# Input(s): data file 'nba2018.csv'
# Output(s): data file 'nba2018-teams.csv'
#            text file 'efficiency-summary.txt'
#                      'teams-summary.txt'
# Author: Dui Lee
# Date: 10-03-2018
# ===================================================================

library(readr)    # importing data
library(dplyr)    # data wrangling
library(ggplot2)  # graphics

# import data
data = read_csv("../data/nba2018.csv")

# In experience, Replace all the occurrences of "R" with 0, and
# then convert the entire column into integers
data$experience[data$experience == "R"] = 0
data$experience = as.integer(data$experience)

# Transform salary so that you have salaries in millions: e.g. 1000000 
data$salary = data$salary / 1000000

# Relabel factors using more descriptive names
levels(data$position) <- 
  c("center", "power_fwd", "point_guard", "small_fwd", "shoot_guard")

# add missed_fg = missed ???eld goals
# add missed_ft = missed free throws
# add rebounds = o???ensive rebounds + defensive rebounds
# add efficiency = e???ciency index
data = mutate(data, 
              missed_fg = field_goals_atts - field_goals,
              missed_ft = points1_atts - points1, 
              rebounds = off_rebounds + def_rebounds,
              efficiency = 
                (points + rebounds + assists + steals + blocks - 
                   missed_fg - missed_ft - turnovers) / games)

# send the R output of summary() on efficiency to a text file named
# efficiency-summary.txt inside the output/ folder. 
sink(file = '../output/efficiency-summary.txt')
summary(data$efficiency)
sink()

# Send the R output of the teams summary to a text file named 
# teams-summary.txt inside the data/ folder
sink(file = '../output/teams-summary.txt')
teams = data %>% group_by(team) %>% select(team,
                                   experience,
                                   salary,
                                   points3,
                                   points2,
                                   points1,
                                   points,
                                   off_rebounds,
                                   def_rebounds,
                                   assists,
                                   steals,
                                   blocks,
                                   turnovers,
                                   fouls,
                                   efficiency) %>% 
  summarise_all(funs(sum))
summary(teams)
sink()

# export the teams table to a csv file named nba2018-teams.csv,
# inside the data/ folder 
write.csv(teams, '../data/nba2018-teams.csv')

