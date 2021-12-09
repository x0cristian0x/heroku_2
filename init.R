my_packages = c("dplyr", "DT","lubridate","tidyr","htmltools","shinythemes",
                "ggplot2", "Rcpp")

install_if_missing = function(p) {
  if (p %in% rownames(installed.packages()) == FALSE) {
    install.packages(p)
  }  else {
    cat(paste("Skipping already installed package:", p, "\n"))
  }
}
# helpers.installPackages("dplyr", "DT","lubridate","tidyr","htmltools","shinythemes",
#                           "ggplot2")


invisible(sapply(my_packages, install_if_missing))