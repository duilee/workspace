#' @title roll
#' @description takes a device and a number of times and return rolls
#' @param x object of class "device"
#' @param times number of times to roll the device (default = 1)
#' @return a list of rolls, sides, prob, total
#' @export
#' @examples
#' device1 <- device()
#'
#' #roll the device 20 times
#' roll20 <- roll(device1, 20)


roll <- function(x, times = 1) {
  if (!is.device(x)) {
    stop("\n'roll()' requires an object 'device'")
  }
  check_times(times)
  outp <- list(rolls = sample(x$side, size = times, replace = TRUE, prob = x$prob),
      sides = x$side,
      prob = x$prob,
      total = times)
  class(outp) <- 'rolls'
  outp
}

#check validity of times
check_times <- function(times) {
  if (length(times) > 1) {
    stop("\n'times' must be a single value")
  }
  if (mode(times) != "numeric") {
    stop("\n'times' must be a numeric value")
  }
  if (times < 1) {
    stop("\n'times' must be a positive number greater than 0")
  }
  return(TRUE)
}


#print method for roll
#' @export
print.rolls <- function(x) {
  cat('object "rolls"\n\n')
  print(x$rolls)
  invisible(x)
}


