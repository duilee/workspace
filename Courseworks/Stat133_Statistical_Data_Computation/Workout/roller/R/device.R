#' @title device
#' @description creates a coin device
#' @param sides vector of k>=2 elements, by default numbers 1 and 2
#' @param prob vector of probabilities for each side (all equal to 1/2 by default)
#' @return creates a coin with given sides and probabilities
#' @export
#' @examples
#' #default
#' dev <- device()
#'
#' #typical die
#' dice <- device(sides = c(1,2,3,4,5,6), prob = rep(1/6, 6))
#'
#' #unfair coin
#' coin <- device(sides = c('head', 'tail'), prob = c(0.3, 0.7))

device <- function(sides = c(1,2), prob = rep(1/2, length(sides))) {
  if (length(sides) != length(prob)) {
    stop("\n'sides' and 'prob' have difference lengths")
  }
  check_sides(sides)
  check_prob(prob)

  coin <- list(side = sides, prob = prob)
  class(coin) = 'device'
  coin

}

#' @title check sides
#' @description checks the validity of the argument sides. sides must be a vecotr with more than one element with no duplicates
#' @param x vector with each side element
#' @return returns boolean value of whether given sides are valid side values
check_sides <- function(x) {
  if (length(x) < 2) {
    stop("\n'sides' must be a vector of length greater than 1")
  }
  for (i in (1:length(x))) {
    if (sum(x[i] == x) > 1) {
      stop("\n'sides' cannot have duplicated elements")
    }
  }
  return(TRUE)
}

#' @title check probabilitiy
#' @description checks the validity of the argument prob. It should be a numeric vector with more than 1 element, containing number between 0 and 1 and sums to 1
#' @param prob numeric vector with prob values
#' @return returns boolean value of whether given sides are valid prob values
check_prob <- function(x) {
  if (length(x) < 2) {
    stop("\n'prob' must be a vector of length greater than 1")
  }
  if (sum(x > 1 | x < 0) > 0) {
    stop("\n'prob' must have value between 0 and 1")
  }
  if (sum(x) != 1) {
    stop("\nelements in 'prob' must add up to 1")
  }
  return(TRUE)
}

#print method for device

#' @export
print.device <- function(x) {
  cat('object "device"\n\n')
  df <- data.frame(side = x$side, prob = x$prob)
  print(df)
  invisible(x)
}

#check whether given object has 'device' class

#' @export
is.device <- function(x) {
  if (class(x) != "device") {
    return(FALSE)
  }
  else {
    return(TRUE)
  }
}
