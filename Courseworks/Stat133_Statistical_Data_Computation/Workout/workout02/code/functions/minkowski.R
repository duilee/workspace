#' @title minkowski distance
#' @description compute minkowski given two numeric vectors representing two points
#' @param x numeric vector for one point
#' @param y numeric vector for the other point
#' @param p either a numeric value greater than 1, or a character string max(default 1)
#' @return numeric value of the minkowski distance
minkowski <- function(x,y,p = 1) {
  if (length(x) != length(y)) {
    stop("x and y have different lengths")
  }
  if (mode(p) == "numeric" & p < 1) {
    stop("p cannot be less than 1")
  }
  if (mode(p) == "character" & p != "max") {
    stop("invalid character value for p")
  }
  if (p != 'max') {
    z = rep(0, length(x))
    for (i in 1:length(x)) {
      z[i] = (abs(x[i] - y[i]))^(p)
    }
    return(sum(z)^(1/p))
  }
  if (p == 'max') {
    z = rep(0, length(x))
    for (i in 1:length(x)) {
      z[i] = (abs(x[i] - y[i]))
    }
    return(max(z))
  }
}

