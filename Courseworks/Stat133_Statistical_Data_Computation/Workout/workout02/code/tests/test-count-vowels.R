context("Tests for count vowels")
test_that("count_vowels works as expected", { 
  fox <- "The quick brown fox jumps over the lazy dog" 
  FOX <- "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG" 
  do <- "do or do not" 
  vowels <- c('a', 'e', 'i', 'o', 'u') 
  counts <- c(1, 3, 1, 4, 2) 
  names(counts) <- vowels

  expect_equal(count_vowels(fox), counts) 
  expect_equal(count_vowels(FOX), counts) 
  expect_length(count_vowels(fox), 5) 
  expect_named(count_vowels(fox), vowels) 
  expect_type(count_vowels(fox), 'double') 
  expect_length(count_vowels(do), 5)
  expect_error(count_vowels(123)) 
  expect_error(count_vowels(TRUE)) 
})
