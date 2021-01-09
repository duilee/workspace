library('stringr')

#' @title count_vowels
#' @description computes the number of vowels of a character string
#' @param x character string to count vowels on. Error if not a character string. 
#' @return numeric vector with names for vowels
count_vowels <- function(x) {
  if (mode(x) != 'character') {
    stop("invalid input; a string was expected")
  }
  y <- tolower(x)
  y <- str_split(y, '')
  vowels <- c('a', 'e', 'i', 'o', 'u')
  z <- rep(0, 5)
  names(z) <- vowels
  for (i in vowels) {
    z[i] = sum((i == y[[1]]))
  }
  return(z)
}
