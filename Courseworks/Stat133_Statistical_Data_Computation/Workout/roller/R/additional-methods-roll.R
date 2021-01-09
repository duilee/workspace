#' @title roll replacement method
#' @description replacement method to replace the value of a given roll
#' @param x object of class "rolls"
#' @param i index of the rolls to be changed
#' @param value new value to be inputted
#' @return new rolls with replaced value
#' @export
#' @examples
#' device2 <- device()
#' roll2 <- roll(device2, 20)
#'
#' #replace 3rd result to 2
#' roll2[2] <- 2

"[<-.rolls" <- function(x, i, value) {
  if (i > x$total) {
    stop("\nGiven index is out of range")
  }
  if (sum(value == x$sides) == 0) {
    stop("\nGiven value is invalid choice of side")
  }
  x$rolls[i] <- value

  newroll <- list(rolls = x$rolls,
              sides = x$sides,
              prob = x$prob,
              total = x$total
              )
  class(newroll) <- "rolls"
  newroll
}

#' @title roll extraction method
#' @description extract the value of given index in the rolls
#' @param x object of class "rolls"
#' @param i index of the rolls to be changed
#' @return value of the rolls at the given index
#' @export
#' @examples
#' device2 <- device()
#' roll2 <- roll(device2, 20)
#'
#' #get the 10th result of roll2
#' roll2[10]

"[.rolls" <- function(x, i) {
  x$rolls[i]
}

#' @title roll addition method
#' @description addition method to add more rolls
#' @param x object of class "rolls"
#' @param n n more times to be added to the rolls
#' @return new 'rolls' object with added rolls
#' @export
#' @examples
#' device2 <- device()
#' roll2 <- roll(device2, 20)
#'
#' #add 10 more rolls
#' roll2 + 10

"+.rolls" <- function(x, n) {
  if (n <= 0) {
    stop("\ninvalid value. Must be positive")
  }
  dev <- device(x$sides, x$prob)
  more_rolls <- roll(dev, n)

  new_roll <- list(rolls = c(x$rolls, more_rolls$rolls),
                   sides = x$sides,
                   prob = x$prob,
                   total = x$total + n)
  class(new_roll) <- 'rolls'
  new_roll
}

