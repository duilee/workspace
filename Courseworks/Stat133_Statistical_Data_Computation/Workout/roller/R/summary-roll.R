#' @title summary roll method
#' @description takes 'rolls' objects and return object 'summary rolls'
#' @param x object of class "rolls"
#' @return a list containing a data frame with side, count, and prop
#' @export
#' @examples
#' device2 <- device()
#' roll2 <- roll(device2, 20)
#'
#' #obtain summary of roll
#' summary(roll2)

summary.rolls <- function(x, ...) {
  countin = rep(0, length(x$sides))
  for (i in (1:length(x$sides))) {
    countin[i] = sum(x$rolls == x$sides[i])
  }
  df = data.frame(side = x$sides,
                  count = countin,
                  prop = countin / x$total)
  result <- list(freqs = df)
  class(result) <- 'summary.rolls'
  result
}

#print method for summary

#' @export
print.summary.rolls <- function(x, ...) {
  cat('summary "rolls"\n\n')
  print(x$freqs)
  invisible(x)
}
