public static void main(String[] args){
  public static boolean skott(int year){
  if(year%4 !=0){return false;}
  if(year%100 !=0){return true;}
  if(year%400==0){return true;}
      else{return false;}
    }
}

