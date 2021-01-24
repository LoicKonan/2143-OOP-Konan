## Assignment 5 - Basic OOP terminology

- Name: Loic Konan
- Date:  28 Jan 2021
- Class: 2143 OOP

## Definitions

#### Class

> In object-oriented programming, a Class is a **user-defined data type**, which holds its own data members and member functions,
> which can be accessed and used by creating an instance of that class. A C++ class is like a ***blueprint for an object***.
>> For example:
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>

#### Object

> In object-oriented programming, an Object is an **instance of a class**. An object is nothing but a self-contained component
> which consists of methods and  properties to make a particular type of data useful.
>> For example:
>
> <img src="https://www.atnyla.com/library/images-tutorials/class-and-object-in-java.PNG" width=450>

#### Method

> A method is a **programmed procedure** that is defined as part of a class and included in any object of that class.
> A method in an object can only have access to the data known to that object, which ensures data integrity among the
> set of objects in an application. A method can be ***re-used*** in multiple objects.
>> For example:
>
><img src="https://miro.medium.com/max/810/1*xiYI_rl-_pX_27BAjxBL3g.png" width=450>

#### Abstraction

> Abstraction in Object-Oriented Programming mean to **"shows" only essential attributes and "hides"**
> unnecessary information. The main purpose of abstraction is hiding the unnecessary details from the users.
>> For example:
>
><img src="https://www.guru99.com/images/abstraction_in_oops_112.png" width=450>

#### Attributes / Properties

> Attributes / Properties are **data stored inside** a class or instance and represent the state or quality of the class or instance.
> In short, attributes / Properties **store information about the instance**.
>> For example:
>
> ><img src="https://miro.medium.com/max/700/1*MV6B2jANikTULx6wFLrcEg.png" width=450>

#### Class Variable

> A Class Variables are shared between a class and all its subclasses. It is also known as **static variables** declared
> with the ***static*** keyword in a class, but outside a method, constructor or a block.
>> For example:
>
> <img src="https://www.programmerinterview.com/images/memVariables.png" width=450>

#### Composition

> It enables creating complex types by combining objects of other types.
> This means that a class Composite can contain an object of another class Component.
> This relationship means that a Composite **has a** Component.
>> For example:
>
> <img src="https://image.slidesharecdn.com/compositionppt-170615151624/95/composition-in-oop-2-638.jpg?cb=1507486822" width=450>

#### Constructor

> Constructors have the **same name** as the class or struct, and they usually **initialize the data members of the new object**.
> In C++, Constructor is automatically called when object (instance of class) create.
>> For example:
> <img src="https://www.studytonight.com/cpp/images/copy-constructor.gif" width=450>

#### Encapsulation

> It refers to the bundling of data with the methods that operate on that data.
> **Encapsulation** is used to hide the values or state of a structured data object inside a class,
> preventing unauthorized parties’ direct access to them.
>> For example:
> <img src="http://www.expertphp.in/images/articles/ArtImgKPTPrr_OOP4.jpg" width=450>

#### Friends

> If a function is **friend function** of a class, then the friend function is not the actual member of the class.
> But that friend function ***has rights to access*** to all private and protected members (variables and functions).
>> For example:
> <img src="https://www.cpp.thiyagaraaj.com/cms/assets/cimages/friend_function.png" width=450>

#### Inheritance

> Is the ability of a class to **derive or inherit** methods and properties from another class.
>> For example:
> <img src="https://www.mycplus.com/mycplus/wp-content/uploads/2008/10/Inheritance-1280x640.png" width=450>

#### Instance Variable

> An **Instance Variable** is a variable which is ***declared in a class but outside*** of constructors,
> methods, or blocks. Instance variables are created when an object is instantiated,
> and are accessible to all the constructors, methods, or blocks in the class.
>> For example:
> <img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113121956/TypesofVariableInC.png" width=450>

#### Member Variable

> A member variable is a variable that is part of a class.
> The member variables of an object are accessed using the dot operator.
>> For example:
> <img src="https://1.bp.blogspot.com/-b-snzBFnoHs/Vu6rs2fUoqI/AAAAAAAAAXQ/CPUenSOSJKsZTxWqwWwn0v-DZde8f8GNQ/s1600/memberVariables.JPG" width=450>

#### Multiple Inheritance

> ***Multiple Inheritance*** is a feature of C++ where a **class can inherit from more than one classes**.
> The constructors of inherited classes are called in the same order in which they are inherited.
>> For example:
> <img src="https://binaryterms.com/wp-content/uploads/2020/06/Multiple-Inheritance-in-Object-Orientation.jpg" width=250>

#### Overloading

> Function overloading is a feature in C++ where two or more functions can have the **same name but different parameters**.
>> For example:
> <img src="https://haygot.s3.amazonaws.com/questions/933713_919938_ans_bb02050cd3e340a18b46ca8ce889579e.png" width=450>

#### Polymorphism

> Polymorphism is the ability of different functions to be invoked with the same name.
> There are two forms:
>
> - Static polymorphism
> - Dynamic polymorphism
>
>> For example:
> <img src="https://i.stack.imgur.com/6Ks3t.png" width=450>

#### Public / Private / Protected

> In C++, there are three access specifiers:
>
> - **Public** - Members are accessible from outside the class.
> - **Private** - Members cannot be accessed (or viewed) from outside the class.
> - **Protected** - Members cannot be accessed from outside the class, however, they can be accessed in inherited classes.
>
>> For example:
> <img src="https://www.bogotobogo.com/cplusplus/images/private_inheritance/class_inheritance_diagram.png" width=250>

#### Static

> **Static** keyword makes any variable, object or function a constant one.
> That means, only one copy of that particular variable or function would be created and will
> be accessed by all the instances of the class. We can use static keyword with:
>
> - **Static Variables** : Variables in a function, Variables in a class
> - **Static Members of Class** : Class objects and Functions in a class
>
>> For example:
> <img src="https://dotnettutorials.net/wp-content/uploads/2018/07/word-image-485-300x136.png" width=450>

#### Virtual

> **A virtual function** is a member function which is declared within a base class and is Overriden by a derived class.
> ***Virtual functions*** ensure that the correct function is called for an object.
>> For example:
> <img src="https://prepinsta.com/wp-content/uploads/2019/02/Virtual-Base-Class-in-C.png" width=450>
