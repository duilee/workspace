#' @title plot roll method
#' @description takes 'rolls' objects and return a barchart of proportions
#' @param x object of class "rolls"
#' @return a barchart of proportions
#' @export
#' @examples
#'  \dontrun{
#'  #roll the default die for 60 times
#'  device3 <- device()
#'  roll3 <- roll(device3, 60)
#'
#'  #create barchard of proportions
#'  plot(roll3)}

plot.rolls <- function(x, ...) {
  dat <- summary(x)
  barplot(dat$freqs$prop, names.arg = dat$freqs$side,
          main = paste('Relative Frequencies in a series of', x$total, 'rolls'),
          xlab = 'sides of device',
          ylab = 'relative frequencies')

}


