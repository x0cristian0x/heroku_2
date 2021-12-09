my_packages = c("dplyr", "DT","lubridate","tidyr","htmltools","shinythemes",
                "Rcpp")

install_if_missing = function(p) {
  if (p %in% rownames(installed.packages()) == FALSE) {
    install.packages(p)
  }
}

invisible(sapply(my_packages, install_if_missing))