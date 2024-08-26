// exemple_Matvey.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};
// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
   //основной словарь {разработчик-список стаусов задач-количество задач}  
   map<string, map<TaskStatus, int>> person_status_task_; 
    // Получение из основного словаря статистику по статусам задач конкретного разработчика 
    const TasksInfo& GetPersonTasksInfo(const string& person) const {

        return person_status_task_.at(person); //{список стаусов задач-количество задач}
    }
    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
      map<TaskStatus, int> asd = person_status_task_[person];
        asd[TaskStatus::NEW] = asd[TaskStatus::NEW] +1;
        person_status_task_[person][TaskStatus::NEW] = asd[TaskStatus::NEW];
        //++person_status_task_[person].at(TaskStatus::NEW);
    }
   
        TasksInfo updated_tasks, not_updated_tasks;
         map<TaskStatus,int> progress;
         map<TaskStatus,int> not_progress;
         map<TaskStatus, int> t_c;//количества переходящих задач по i тому значению(передвинулось со значения на следующее)

    // Обновить статусы по данному количеству задач конкретного разработчика, подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {

        //цикл определения количества переходящих задач t_c по i тому значению (передвинулось со значения на следующее)
        for (int i = static_cast<int> (TaskStatus::NEW); i < static_cast<int> (TaskStatus::DONE); ++i) {
  
            if ((person_status_task_[person][TaskStatus(i)]) >= task_count) {
                t_c[TaskStatus(i)] = task_count;  //обновленные для i в сумме с пеершедшими
            }
            if ((person_status_task_[person][TaskStatus(i)]) < task_count) {
                t_c[TaskStatus(i)] = person_status_task_[person][TaskStatus(i)];
            }
            if (task_count==0) {
                t_c[TaskStatus(i)] = 0;
            }
            // счетчик уменьшения значения обновлений в цикле
            task_count = task_count - person_status_task_[person][TaskStatus(i)]; 
            if (task_count < 0) {
                task_count = 0;
            }
         }

        for (int i = static_cast<int> (TaskStatus::NEW); i < static_cast<int> (TaskStatus::DONE); ++i) {

           //значение оставшееся на i той позиции после перемещения заданного t_c
           // person_status_task_[person][TaskStatus(i)] = person_status_task_[person][TaskStatus(i)] - t_c[TaskStatus(i)];
            not_progress[TaskStatus(i)] = person_status_task_[person][TaskStatus(i)] - t_c[TaskStatus(i)];
         
            updated_tasks[TaskStatus(i)] = progress[TaskStatus(i)];//обновление словаря обновлений           
            not_updated_tasks[TaskStatus(i)] = not_progress[TaskStatus(i)]; //обновление словаря не обновленных
            
            //обновившиеся задачи для последующего i+1 занчения как перешедшие с i-го значения
            progress[TaskStatus(i + 1)] = t_c[TaskStatus(i)];

            if (i == 2) {
             updated_tasks[TaskStatus(3)] = progress[TaskStatus(3)];
            }
        }

            person_status_task_[person][TaskStatus::NEW] = not_updated_tasks[TaskStatus::NEW] + updated_tasks[TaskStatus::NEW];
            person_status_task_[person][TaskStatus::IN_PROGRESS] = not_updated_tasks[TaskStatus::IN_PROGRESS] + updated_tasks[TaskStatus::IN_PROGRESS];
            person_status_task_[person][TaskStatus::TESTING] = not_updated_tasks[TaskStatus::TESTING] + updated_tasks[TaskStatus::TESTING];
            person_status_task_[person][TaskStatus::DONE] = person_status_task_[person][TaskStatus::DONE] + updated_tasks[TaskStatus::DONE];

            return tie(updated_tasks, not_updated_tasks);       
    }

/*Метод PerformPersonTasks принимает параметры: person — имя разработчика, task_count — 
количество выполненных задач. Его алгоритм таков:
Рассмотреть все невыполненные задачи разработчика person.
Упорядочить их по статусам: сначала все задачи в статусе NEW, затем все задачи в 
статусе IN_PROGRESS и, наконец, задачи в статусе TESTING.
Рассмотреть первые task_count задач и перевести каждую из них в 
следующий статус в соответствии с естественным порядком: NEW → IN_PROGRESS → TESTING → DONE.
Этот метод возвращает пару из двух элементов:
Словарь со статусами обновившихся задач: количество обновившихся задач по каждому статусу.
Информацию о невыполненных задачах — тех, статус которых не DONE и не изменился. 
Также в виде словаря, хранящего количество по статусу.*/  
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь.
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks"s
        << ", "s << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress"s
        << ", "s << tasks_info[TaskStatus::TESTING] << " tasks are being tested"s
        << ", "s << tasks_info[TaskStatus::DONE] << " tasks are done"s << endl;
}

int main() {
    TeamTasks tasks;
    TasksInfo updated_tasks, untouched_tasks;

    tasks.AddNewTask("Ilia"s);
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan"s);
    }
    cout << "Ilia's tasks: "s; 
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"s));
    cout << "Ivan's tasks: "s;
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"s));
    cout << endl;
    cout << "---------------------------"s << endl;;

   

   tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 2);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    cout << endl;
    cout << "---------------------------"s << endl;;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 2);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    cout << endl;
    cout << "---------------------------"s << endl;;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 4);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    cout << endl;
    cout << "---------------------------"s << endl;;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 8);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    cout << endl;
    cout << "---------------------------"s << endl;;
    

    cout << endl << "Test sample" << endl << endl;

    
    // Test sample: Passed
   
    tasks.AddNewTask("Ilia"s);
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan"s);
    }
    cout << "Ilia's tasks: "s;
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"s));
    cout << "Ivan's tasks: "s;
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"s));

   

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 2);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 2);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    

    // Test 1: Passed
    
    cout << endl << "Test 1" << endl << endl;
    TeamTasks tasks1;
    for (int i = 0; i < 3; ++i) {
        for (int i = 0; i < 5; ++i) {
            tasks1.AddNewTask("Ivan"s);
        }
        cout << "======================================================"s << endl;
        tie(updated_tasks, untouched_tasks) = tasks1.PerformPersonTasks("Ivan"s, 10);
        cout << "Ivan's tasks: "s;
        PrintTasksInfo(tasks1.GetPersonTasksInfo("Ivan"s));
        cout << "Updated Ivan's tasks: "s;
        PrintTasksInfo(updated_tasks);
        cout << "Untouched Ivan's tasks: "s;
        PrintTasksInfo(untouched_tasks);
    }

    // Test 2: Passed
   
    cout << endl << "Test 2" << endl << endl;
    TeamTasks tasks2;
    tasks2.AddNewTask("Ivan"s);
    cout << "Ivan's tasks: "s;
    PrintTasksInfo(tasks2.GetPersonTasksInfo("Ivan"s));
    for (int i = 0; i < 4; ++i) {
        cout << "======================================================"s << endl;
        tie(updated_tasks, untouched_tasks) = tasks2.PerformPersonTasks("Ivan"s, 1);
        cout << "Ivan's tasks: "s;
        PrintTasksInfo(tasks2.GetPersonTasksInfo("Ivan"s));
        cout << "Updated Ivan's tasks: "s;
        PrintTasksInfo(updated_tasks);
        cout << "Untouched Ivan's tasks: "s;
        PrintTasksInfo(untouched_tasks);
    }
    cout << "======================================================"s << endl;
    tasks2.AddNewTask("Ivan"s);
    PrintTasksInfo(tasks2.GetPersonTasksInfo("Ivan"s));
    cout << "======================================================"s << endl;
    tie(updated_tasks, untouched_tasks) = tasks2.PerformPersonTasks("Ivan"s, 0);
    cout << "Ivan's tasks: "s;
    PrintTasksInfo(tasks2.GetPersonTasksInfo("Ivan"s));
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    cout << "======================================================"s << endl;
    tie(updated_tasks, untouched_tasks) = tasks2.PerformPersonTasks("Ivan"s, 1);
    cout << "Ivan's tasks: "s;
    PrintTasksInfo(tasks2.GetPersonTasksInfo("Ivan"s));
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    tasks2.AddNewTask("Ivan"s);
    cout << "======================================================"s << endl;
    tie(updated_tasks, untouched_tasks) = tasks2.PerformPersonTasks("Ivan"s, 1);
    cout << "Ivan's tasks: "s;
    PrintTasksInfo(tasks2.GetPersonTasksInfo("Ivan"s));
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    tasks2.AddNewTask("Ivan"s);
    cout << "======================================================"s << endl;
    tie(updated_tasks, untouched_tasks) = tasks2.PerformPersonTasks("Ivan"s, 3);
    cout << "Ivan's tasks: "s;
    PrintTasksInfo(tasks2.GetPersonTasksInfo("Ivan"s));
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    cout << "======================================================"s << endl;
    tie(updated_tasks, untouched_tasks) = tasks2.PerformPersonTasks("Ivan"s, 3);
    cout << "Ivan's tasks: "s;
    PrintTasksInfo(tasks2.GetPersonTasksInfo("Ivan"s));
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    


    // Test 3: Passed
    cout << endl << "Test 3" << endl << endl;
    TeamTasks tasks3;
    for (int i = 1; i <= 3; ++i) {
        tasks3.AddNewTask("Ivan"s);
        cout << "======================================================"s << endl;
        tie(updated_tasks, untouched_tasks) = tasks3.PerformPersonTasks("Ivan"s, i);
        cout << "Ivan's tasks: "s;
        PrintTasksInfo(tasks3.GetPersonTasksInfo("Ivan"s));
        cout << "Updated Ivan's tasks: "s;
        PrintTasksInfo(updated_tasks);
        cout << "Untouched Ivan's tasks: "s;
        PrintTasksInfo(untouched_tasks);
    }
    
}

