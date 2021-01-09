context("Verify Roll")

test_that("check_times with valid value", {
  expect_true(check_times(500))
  expect_true(check_times(200))
  expect_true(check_times(5))
})

test_that("check_times error with non-numeric value", {
  expect_error(check_times("Japan"))
  expect_error(check_times("Cal"))
})

test_that("check_times error with length greater than 2", {
  expect_error(check_times(c(2,5)))
  expect_error(check_times(c(1,2,3,4)))
})

test_that("roll returns an object with class 'rolls'", {
  expect_true(class(roll(device())) == 'rolls')
})

