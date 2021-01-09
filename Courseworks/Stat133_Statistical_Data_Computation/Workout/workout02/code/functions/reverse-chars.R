library('stringr')

#' @title reverse_chars
#' @description reverse string by characters
#' @param x character string to be reversed
#' @return reversed string by character
reverse_chars <- function(x) {
  if (mode(x) != 'character') {
    stop("invalid input; must be a string")
  }
  z = rep(0, nchar(x))
  for (i in 1:nchar(x)) {
    z[i] = str_sub(x, -i, -i)
  }
  return(paste(z, collapse = ''))
}

