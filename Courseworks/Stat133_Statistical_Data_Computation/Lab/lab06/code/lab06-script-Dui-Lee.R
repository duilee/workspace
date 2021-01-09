# ===================================================================
# Title: Stat133-Lab06
# Description:
#   Data fram manipulation with "dplyr", and plotting graphs
#   with "ggplot2"
# Input(s): data file 'nba2018-players.csv'
# Output(s): data file 'warriors.csv', 'lakers.csv'
#             Image file 'height_weight_by_position.pdf', 
#                         'histogram-age.pdf', 
#                         'points-salary.pdf',
#                         'histogram-age.jpeg',
#                         'sactterplot-height-weight.png',
#                         'scatterplot-height-weight-HD.png'
#             Text file 'data-structure.txt'
#                       'summary-lakers.txt'
#                       'summary-warriors.txt'
# Author: Dui Lee
# Date: 10-03-2018
# ===================================================================

# packages
library(readr)    # importing data
library(dplyr)    # data wrangling
library(ggplot2)  # graphics

##Exporting some data tables

# Use read_csv() from the package "readr" 
# to import the data nba2018-players.csv in R
data = read_csv("../data/nba2018-players.csv")

# Use the imported tibble to create a data frame warriors by 
# selecting rows???e.g. filter()???of Golden State Warriors, 
# arranging rows by salary in increasing order.
warriors = arrange(filter(data, team == "GSW"), salary)

# Use the function write.csv() to export (or save) the data frame warriors
write.csv(warriors, file = "../data/warriors.csv", row.names = FALSE)

# Create another data frame lakers by selecting rows of Los Angeles Lakers,
# this time arranging rows by experience (decreasingly).
lakers = arrange(filter(data, team == "GSW"), desc(experience))

# Now use the function write_csv() to export (or save) the data frame lakers
write_csv(lakers, "../data/lakers.csv")

##Exporting some R output

# Export the output of str() on the data frame with all the players.
sink(file = '../output/data-structure.txt')
str(data)
sink()

# Export the summary() of the entire data frame warriors 
# to a text file summary-warriors.txt
sink(file = '../output/summary-warriors.txt')
summary(warriors)
sink()

# Export another summary() of the entire data frame lakers
# to a text file summary-lakers.txt
sink(file = '../output/summary-lakers.txt')
summary(lakers)
sink()

## Exporting some ¡°base¡± graphs

# Open the help documentation of png() and related graphic devices.
?png()

# Use png() to save a scatterplot of height and weight with plot().
# Save the graph in the images/ folder.
png(filename = "../images/scatterplot-height-weight.png")
plot(data$height, data$weight, pch = 20, 
     xlab = 'Height', ylab = 'Weight')
dev.off()

# Save another version of the scatterplot between height and weight,
# but now try to get an image with higher resolution. Save the plot in images/.
png(filename = "../images/scatterplot-height-weight-HD.png", width = 1920, height = 1080)
plot(data$height, data$weight, pch = 20, 
     xlab = 'Height', ylab = 'Weight')
dev.off()

# Save a histogram in JPEG format of age with dimensions 
# (width x height) 600 x 400 pixels. Save the plot in images/.
jpeg(filename = "../images/histogram-age.jpeg", width = 600, height = 400)
hist(data$age)
dev.off()

# Use pdf() to save the previous histogram of age in PDF format, 
# with dimensions (width x height) 7 x 5 inches.
pdf(file = "../images/histogram-age.pdf", width = 7, height = 5)
hist(data$age)
dev.off()

## Exporting some ggplots

# Use ggplot() to make a scatterplot of points and salary, 
# and store it in a ggplot object named gg_pts_salary. 
# Then use ggsave() to save the plot with dimensions (width x height) 7 x 5 inches
# in the images/ folder as points_salary.pdf

gg_pts_salary = ggplot(data = data, aes(x=points, y=salary)) + geom_point()

ggsave("points_salary.pdf", plot = gg_pts_salary, path = "../images" , width = 7, height = 5)

# Use ggplot() to create a scatterplot of height and weight,
# faceting by position. Store this in a ggplot object gg_ht_wt_positions
# Then use ggsave() to save the plot with dimensions (width x height) 
# 6 x 4 inches; in the images/ folder as height_weight_by_position.pdf

gg_ht_wt_positions = 
  ggplot(data = data, aes(x=points, y=salary)) + geom_point() + facet_wrap(~position)

ggsave("height_weight_by_position.pdf",
       plot = gg_ht_wt_positions, path = "../images" , width = 6, height = 4)

##More "dplyr"

#display the player names of Lakers 'LAL'.
data %>% filter(team == "LAL") %>% select(player)

#display the name and salary of GSW point guards ¡®PG¡¯.
data %>% filter(position == 'PG') %>% select(player, salary)

#dislay the name, age, and team, of players with more than 
#10 years of experience, making 10 million dollars or less.
data %>% filter(experience > 10, salary <= 10000000) %>% select(player, age, team)

#select the name, team, height, and weight, of rookie players,
#20 years old, displaying only the first five occurrences (i.e. rows).
data %>% filter(experience == 0) %>% select(player, team, height, weight) %>% head(5)

#create a data frame gsw_mpg of GSW players, that contains 
#variables for player name, experience, and min_per_game 
#(minutes per game), sorted by min_per_game (in descending order).
gsw_mpg = data %>% mutate(min_per_game = minutes / games) %>% 
  arrange(desc(min_per_game)) %>% select(player, experience, min_per_game)

#display the average triple points by team, in ascending 
#order, of the bottom-5 teams (worst 3pointer teams).
data %>% select(team, points3) %>% group_by(team) %>% 
  summarise(avg_points3 = mean(points3)) %>% 
  arrange(avg_points3) %>% head(5)

#obtain the mean and standard deviation of age, for 
#Power Forwards, with 5 and 10 years (including) of experience.
data %>% filter(experience <= 10, experience >= 5, position == "PF") %>%
  summarise(mean_age = mean(age), sd_age = sd(age))

