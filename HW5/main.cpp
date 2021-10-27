//Question 7
bool isGrammar(string str){
  if (str is length 1){
    if (str is 'Q','P','R'){
      return true;
    }
  } if (first character is 'Q' or 'P' and last character is '1'){
    return isGrammar(string without first and last character);
  }
  return false;
}

//Question 8
bool isGrammar(string str){
  if (length of str is 0){
    return true;
  }
  if (length of str 1){
    if (str is '&' or '#'){
      return true;
    }
  }
  if (first character is '&' or '#' or 'W' or 'A' and last character is '&' or '#' or 'W' or 'A'){
    return isGrammar(str without first and last character)''
  }
  return false;
}