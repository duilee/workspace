% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/device.R
\name{check_prob}
\alias{check_prob}
\title{check probabilitiy}
\usage{
check_prob(x)
}
\arguments{
\item{prob}{numeric vector with prob values}
}
\value{
returns boolean value of whether given sides are valid prob values
}
\description{
checks the validity of the argument prob. It should be a numeric vector with more than 1 element, containing number between 0 and 1 and sums to 1
}
