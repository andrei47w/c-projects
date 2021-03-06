# YT Manager

## Requirements
- The application must be implemented in C++ and use layered architecture.
- Provide tests and specifications for non-trivial functions outside the UI. Test coverage must be at least 98% for all layers, except the UI
- Have at least 10 entities in your memory repository
- Validate all input data
- Handle the following situations:
    - If an entity that already exists is added, a message is shown and the entity is not stored. You must decide what makes an entity unique.
    - If the user tries to update/delete an entity that does not exist, a message will be shown and there will be no effect on the list of entities.

1. Replace the templated DynamicVector with the STL vector. Use STL algorithms wherever possible in your application (e.g. in your filter function you could use `copy_if`, `count_if`). Replace all your for loops either with STL algorithms, or with C++11's ranged-based for loop.

2. Store data in a text file. When the program starts, entities are read from the file. Modifications made during program execution are stored in the file. Implement this using the `iostream` library. Create insertion and extraction operators for your entities and use these when reading/writing to files or the console.

3. Use exceptions to signal errors:
    - from the repository;
    - validation errors – validate your entities using Validator classes;
    - create your own exception classes.
    - validate program input.

4.	Depending on your assignment, store your (adoption list, movie watch list, shopping basket or tutorial watch list) in a file. When the application starts, the user should choose the type of file between `CSV` or `HTML`. Depending on the type, the application will save the list in the correct format.

    **Indications**\
    The CSV file will contain each entity on one line and the attributes will be separated by comma \
    The HTML file will contain a table, in which each row holds the data of one entity. The columns of the table will contain the names of the data attributes.\
    These are exemplified in the [example.csv](example.csv) and [example.html](example.html) files.
    `CSV` and `HTML` files are used to save and display data to the user; they act as program outputs, so data should not be read from them!

5. Add a new command, allowing the user to see the:
    * adoption list
    * movie watch list
    * shopping basket
    * tutorial watch list\
Displaying the list means opening the saved file (`CSV` or `HTML`) with the correct application (`CSV` files using Notepad, Notepad++, Microsoft Excel etc. and `HTML` files using a browser)

6. Create a UML class diagram for your entire application. For this, you can use any tool that you like ([StarUML](https://staruml.io/) or [LucidChart](https://www.lucidchart.com/) are only some examples. Many other options exist.


7. Add multiple *undo* and *redo* functionality for the `add`, `remove`, and `update` operations. Implement this functionality using inheritance and polymorphism. You will have **Undo** and **Redo** buttons on the GUI, as well as a key combination to undo and redo the operations (e.g. `Ctrl+Z`, `Ctrl+Y`).

8. Show the contents of the `adoption list` / `movie watch list` / `shopping basket` / `tutorial watch list` using a table view. You must use the [Qt View/Model](https://doc.qt.io/qt-5/modelview.html) components (`QTableView`). Create your own model – a class which inherits from [`QAbstractTableModel`](https://doc.qt.io/qt-5/qabstracttablemodel.html).

## Bonus Possibility [0.1p]
Add multiple *undo* and *redo* functionality for the `adoption list` / `movie watch list` / `shopping basket` / `tutorial watch list`. This will be tested through the application's GUI.

## Bonus Possibility [0.1p]
Use custom Qt delegates. In one of the columns of the Qt table view that shows the elements of the `adoption list` / **etc...**, display an image of the dog, trench coat or a play button that plays the movie trailer or the tutorial - depending on the problem statement. See the example images below.

![image](https://user-images.githubusercontent.com/25611695/119180503-0bfef700-ba79-11eb-86ae-3a42d41bb437.png)
![image](https://user-images.githubusercontent.com/25611695/119180582-2507a800-ba79-11eb-921c-22f64a05522b.png)

## Master C++
You are very passionate about programing (otherwise you wouldn't be reading this) and C++ is a language close to your heart. On your way to becoming a guru, you study a lot and watch many list. To make sure you do not miss any good list, you absolutely need a software application to help you manage your list and create watch lists. The application can be used in two modes: administrator and user. When the application is started, it will offer the option to choose the mode.\
**Administrator mode:** The application will have a database , which holds all the list. You must be able to update the database, meaning: add a new tutorial, delete a tutorial and update the information of a tutorial. Each **List** has a `title`, a `presenter` (name of the presenter person), a `duration` (minutes and seconds), a number of `likes` and a `link` towards the online resource containing the tutorial. The administrators will also have the option to see all the list in the database.\
**User mode:** A user can create a watch list with the list that he/she wants to watch. The application will allow the user to:
- See the list in the database having a given presenter (if the presenter name is empty, see all the list), one by one. When the user chooses this option, the data of the first tutorial (title, presenter, duration, number of likes) is displayed and the tutorial is played in the browser.
- If the user likes the tutorial, he/she can choose to add it to his/her tutorial watch list.
- If the tutorial seems uninteresting, the user can choose not to add it to the watch list and continue to the next. In this case, the information corresponding to the next tutorial is shown and the user is again offered the possibility to add it to the watch list. This can continue as long as the user wants, as when arriving to the end of the list of list with the given presenter, if the user chooses next, the application will again show the first tutorial.
- Delete a tutorial from the watch list, after the user watched the tutorial. When deleting a tutorial from the watch list, the user can also rate the tutorial (with a like), and in this case, the number of likes for the tutorial will be increased.
- See the watch list.