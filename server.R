source("oms_server.R")
source("week_server.R")
source("pregnation_server.R")
source("premature_server.R")
source("function_app/grafica_function.R")
source("function_app/tabla_function.R")

sourceCpp("function_app/read_function.cpp")


shinyServer(function(input, output,session) {
 
 
   omsServer("TABLA_OMS")
   weekServer("TABLA_WEEK")
   pregnationServer("TABLA_PREGNATION")
   prematureServer("TABLA_PREMATURE")
  

  


})
