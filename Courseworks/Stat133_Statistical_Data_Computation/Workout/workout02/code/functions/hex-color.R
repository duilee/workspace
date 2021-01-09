library('stringr')

#' @title is_hex
#' @description determine whether the given string is hexadecimal color notation
#' @param x character string supposed to represent hex notation
#' @return logical value of whether given string is hex notation
is_hex <- function(x) {
  if (mode(x) != 'character') {
    stop("invalid input; a string was expected")
  }
  chk = str_split("ABCDEF0123456789", '')
  y = toupper(x)
  if (nchar(y) != 7) {
    return(FALSE)
  }
  if (substr(y, 1, 1) != '#') {
    return(FALSE)
  }
  for (i in 2:nchar(y)) {
    if (sum((substr(y, i, i) == chk[[1]])) == 0) {
      return(FALSE)
    }
  }
  return(TRUE)
}

#' @title is_hex_alpha
#' @description determine whether the given string is hexadecimal color notation with alpha transparency
#' @param x character string supposed to represent hex notation with alpha transparency
#' @return logical value of whether given string is hex notation with alpha transparency
is_hex_alpha <- function(x) {
  if (mode(x) != 'character') {
    stop("invalid input; a string was expected")
  }
  chk = str_split("ABCDEF0123456789", '')
  y = toupper(x)
  if (nchar(y) != 9) {
    return(FALSE)
  }
  if (substr(y, 1, 1) != '#') {
    return(FALSE)
  }
  for (i in 2:nchar(y)) {
    if (sum(substr(y, i, i) == chk[[1]]) == 0) {
      return(FALSE)
    }
  }
  return(TRUE)
}
