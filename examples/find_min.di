var items_list = List(10,9,0,29,1);

var min = find_min(items_list){
  var min = 0;
  for(var i = 1;i<items_list.len();i++){
    if(items_list(i)<min){
      min = items_list(i);
    }
  }
  return min;
}

print("minimum value is: "+min(items_list));

```bash
minimum value is: 0
```
