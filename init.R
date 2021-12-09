my_packages = c("dplyr", "DT","lubridate","tidyr","htmltools","shinythemes",
                "ggplot2", "remotes", "Rcpp")

install_if_missing = function(p) {
  if (p %in% rownames(installed.packages()) == FALSE) {
    install.packages(p, dependencies = TRUE)
  }  else {
    cat(paste("Skipping already installed package:", p, "\n"))
  }
}
remotes::install_github('talgalili/installr')
installr::install.Rtools()

invisible(sapply(my_packages, install_if_missing))