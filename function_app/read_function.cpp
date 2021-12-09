#include <Rcpp.h>
using namespace Rcpp;

// Function for read table, nutrition

// [[Rcpp::export]]
String read_function(double variable, String distribution, DataFrame tabla){
  String a = "";
  
  if ( distribution == "z" ) {
    double b = tabla[2];
    double c = tabla[3];
    double d = tabla[4];
    double e = tabla[6];
    double f = tabla[7];
    double g = tabla[8];
    
    if ( variable <= b) {
      return a = "El valor se encuentra dentro de -3 SD";
    } else if ( (variable > b) & (variable <= c ))  {
      return a = "El valor se encuentra dentro de -2 SD";
    } else if ( (variable > c) & (variable <= d ))  {
      return a = "El valor se encuentra dentro de -1 SD";
    } else if ( (variable > d) & (variable < e ))  {
      return a = "El valor se encuentra dentro de la Mediana";
    } else if (( variable >= e) & (variable < f )) {
      return a = "El valor se encuentra dentro de +1 SD";
    } else if ( (variable >= f) & (variable < g ))  {
      return a = "El valor se encuentra dentro de +2 SD";
    } else if ( variable >= g)  {
      return a = "El valor se encuentra dentro de +3 SD";
    }
  }else{
    double b = tabla[2];
    double c = tabla[3];
    double d = tabla[5];
    double e = tabla[6];
    
    if ( variable <= b) {
      return a = "El valor se encuentra dentro del percentil 3" ;
    } else if ( (variable > b) & (variable <= c) )  {
      return a = "El valor se encuentra dentro del percentil 15" ;
    } else if ( (variable > c) & (variable < d))  {
      return a = "El valor se encuentra dentro de la Mediana"; 
    } else if ( (variable >= d) & (variable < e ))  {
      return a = "El valor se encuentra dentro del percentil 85"  ;
    } else {
      return a = "El valor se encuentra dentro del percentil 97"  ;
    }
  }
}

// Function for Waterlow

// [[Rcpp::export]]
String waterlow(int date_born, double height, double weight, 
                double height_median, double weight_median ){
  
  double cronico = (height/height_median)*100;
  double agudo = (weight/weight_median)*100;
  
  double cronico_normal = 90;
  double agudo_normal = 80;
  String answer = "";
  int limite_born = 120;
  
  if ( date_born <= limite_born) {
    
    if ( (cronico > cronico_normal) & (agudo < agudo_normal)) {
      return answer= "Desnutrido agudo (emaciado)";
    } else if( (cronico < cronico_normal) & (agudo < agudo_normal)){
      return answer= "Desnutrido crónico agudizado (emaciado y acortado)";
    } else if( (cronico < cronico_normal) & (agudo > agudo_normal)){
      return answer= "Desnutrido crónico (acortado)";
    } else {return answer = "Normal";}
  } else { 
    return answer = "La clasificación es para menores de 10 años";
  } 
}

// Function for pregnation

// [[Rcpp::export]]
String func_pregnation( double bmi_pregnation, DataFrame obesidad,
                        DataFrame sobrepeso, DataFrame normal) {
  String b= "";
  double obe= obesidad[0];
  double sobre= sobrepeso[0];
  double nor = normal[0];
  
  if ( bmi_pregnation >= obe  ) {
    return b = "La gestante tiene OBESIDAD";
    
  } else if ( (bmi_pregnation < obe) & (bmi_pregnation >=  sobre) ) {
    return b = "La gestante tiene SOBREPESO";
    
  } else if ( (bmi_pregnation < sobre) & (bmi_pregnation >=  nor) ) {
    return b = "La gestante tiene peso NORMAL";
    
  } else  {
    return b = "La gestante tiene BAJO PESO";
  }
}