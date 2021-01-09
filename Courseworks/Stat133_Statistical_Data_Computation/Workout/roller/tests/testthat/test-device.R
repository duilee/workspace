context("Verify Device")

test_that("Verify check_side with valid side", {

  expect_true(check_sides(c(1, 2, 3, 4, 5, 6)))
  expect_true(check_sides(c("Korea", "Japan", "China")))
})

test_that("check_side returns error for invalid length", {
  expect_error(check_sides(c("Japan")))
  expect_error(check_sides(c("1")))
})

test_that("check_side error for duplicates", {
  expect_error(check_sides(c(1,2,3,1)))
  expect_error(check_sides(c("Korea", "Korea", "Japan")))
  expect_error(check_sdies(c("stat133", "stat133")))
})

test_that("check_prob works for valid probailities", {
  expect_true(check_prob(c(0.3, 0.3, 0.4)))
  expect_true(check_prob(c(0.25, 0.25, 0.25, 0.25)))
})

test_that("check_prob returns error for non-numeric value", {
  expect_error(check_prob(c("stat133", 0.4, 0.6)))
  expect_error(check_prob(c(0.3, 0.2, "stat", 0.5)))
  expect_error(check_prob(c("Korea", "Japan")))
})

test_that("check_prob returns error for sum(prob) != 1", {
  expect_error(check_prob(c(100, 200, 300)))
  expect_error(check_prob(c(1,2,3,4,5)))
  expect_error(check_prob(c(12, 13, 14, 15, 16)))
})

test_that("device returns an object of 'device'", {
  expect_true(class(device()) == 'device')
})

