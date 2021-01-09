context("Test for reverse_chars")

test_that("reverse_chars() works as expected", { 
  pets <- "step on no pets" 
  ep <- "expecto patronum" 
  pe <- "munortap otcepxe" 
  car_cat <- "Was it a car or a cat I saw?" 
  tac_rac <- "?was I tac a ro rac a ti saW"
  expect_equal(reverse_chars(pets), pets) 
  expect_equal(reverse_chars(ep), pe) 
  expect_equal(reverse_chars(car_cat), tac_rac) 
  expect_length(reverse_chars(car_cat), 1) 
  expect_type(reverse_chars(car_cat), "character") 
  expect_equal(nchar(reverse_chars(car_cat)), nchar(reverse_chars(tac_rac))) 
})
