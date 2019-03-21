function SingleDBD(a, b){
  if(a < b){
    let temp = a;
    a = b;
    b = temp;
  }
  let q;
  while(b > 0){
    q = a%b;
    a = b;
    b = q;
  }
  return a;
}


function DBD(Arr){
  for(var i = 0; i < Arr.length-1; i++){
    Arr[i+1] = SingleDBD(Arr[i], Arr[i+1]);
  }
  return Arr[i];
}

function SingleMBK(a, b){
  return Math.abs(a*b)/SingleDBD(a, b);
}

function MBK(Arr){
  for(var i = 0; i < Arr.length-1; i++){
      Arr[i+1] = SingleMBK(Arr[i], Arr[i+1]);
  }
    return Arr[i];
}

Arr = [2, 65, 6, 10, 5];

console.log(MBK(Arr));



