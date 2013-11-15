LIST
====

Data Structure HW1.


## Subject

For a linked list of integers, create a user-friendly, men-driven program that performs the following operations.
1. Create a list of integers.2. Insert an integer at the end of a list. 3. Search for an integer.4. Delete an integer.5. Print out a list.


## Compile and Run

compile:

```
make
```

run:

```
./list
```

clean:

```
make clean
```

## Usage

This program provides a command-line interface that allows users to create and manipulate linked-lists. The available commands are listed below.

### commands

#### create
 Create a new list.  
 Usage: `create <new_list_name>`.

#### list
 Print out all lists.

#### destroy
 Delete a list.  
 Usage: `destroy <list_to_destory>`.

#### select
 Select a list to use. The selected list will be shown in the prompt.  
 Usage: `select <list_name>`.

#### use
 Same as 'select'.

#### add
 Add an node/nodes at the end of the selected list.  
 Usage: `add <data> [data2] [data3] [...]`.

#### insert
 Insert an node to the nth position of the selected list.  
 Usage: `insert <n> <data>`.

#### delete
 Delete the nth node of the selected list.  
 Usage: `delete <n>`.

#### clear
 Delete all nodes from the selected list.

#### get
 Get the nth item from the selected list.  
 Usage: `get <n>`.

#### find
 Find an node with its data from the selected list.  
 Usage: `find <data>`.

#### print
 Print out the selected list.

#### quit
 Quit this application.

#### help
 Show the help message.

## Definition and Details- 使用 GNU Readline Library- See `*.h`
- `data_structure.h`  - 建立 "LinkedList" 類別，作為一串 List 使用
    - 定義基本操作方法，包含取得長度、取得節點、增刪節點  - 建立 "LinkedListNode" 結構，為 LinkedList 之節點  - 建立 "LinkedListData" 結構，為 LinkedListNode 之資料存放區    - 可選擇 "number" 存放一整數，或 "list" 結構存放一 LinkedList 物件      - 其中 "list" 結構要能存放 (字串)鏈表名稱 與 (指標)LinkedList物件- 主程式一開始即宣告一個名為 lists 的 LinkedList，用來存放之後建立的所有 LinkedList
## Discussion and Conclusion
我不會寫程式 > <
