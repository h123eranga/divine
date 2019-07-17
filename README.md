# divine
Divine is a new server side general purpose, high level programming language for those who are familiar with javascript and the extension would be .di

The language is under construction but super exited to share some of the syntaxes. This would be a intepreted language designed by c++ and may be in future this would be a compiled language.

# Variables

```bash
var variable_1 = 10;
var variable_2 = "Hello";
var variable_3 = 'D';
var variable_4 = true;
var variable_5 = 10.90;

var variable_6 = Integer(10);
var variable_7 = String("Hello");
var variable_8 = Char('H');
var variable_9 = Boolean(true);
var variable_10 = Float(10.38);
```

# Functions

```bash
my_function_1(){
  print("Hi, Welcome to Divine");
}

my_function_2(a){
  print("Value of a is:"+a);
}

my_function_3(a: Integer()){
  print("Value of a is:"+a);
}
```

# Classes

```bash
Address(street_no, street_name, city){

}

Person(id, name, age, Address){
  
}
```

# Inheritance

```bash
Student(school_name, class_name, marks) extends Student{

}

Student(school_name, class_name, marks) extends Student(id,name,age){

}
```

# import statements

```bash
import("core")
import("math")
import("io")
```

# objects

```bash
var address_1 = Address(19, "Street Name", "City");
var std_1 = Person(10,"Haris", 24, address_1);
```
