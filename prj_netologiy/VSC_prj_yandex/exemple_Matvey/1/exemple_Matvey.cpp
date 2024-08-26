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

   // int d_, x_;

  /*  int MathYXD(int& n, int& x, int& d) {
        int y = (n+d)-x;
        if (y <= 0) {
            y = 0;       
            x = abs(x - (n + d));
            d = n;
        }
        if (y > 0) {
            //y = y;           
            d = x;
            x = 0;
        }
        return y;
    }*/
    
    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже

   int progress;
    int not_progress;
    // int d = 0;

    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
        //-----------------------------------------------------------------
        TasksInfo updated_tasks, not_updated_tasks;
   


        if (task_count == 0)
        {
            tuple<TasksInfo, TasksInfo> not_tasks;
            return not_tasks;
        }

        for (int i = static_cast<int> (TaskStatus::NEW); i < static_cast<int> (TaskStatus::DONE); ++i)
        {
            int x_p_s_i = person_status_task_[person][TaskStatus(i)];

            if (task_count == 0)
            {
                break;
            }

            if (progress >= 0)
            {
                updated_tasks[TaskStatus(i)] = progress;          
            }
            if (not_progress > 0)
            {
                not_updated_tasks[TaskStatus(i)] = not_progress;

               /*if (x_p_s_i - progress > 0)
                {
                    not_updated_tasks[TaskStatus(i)] = x_p_s_i - progress;
                }
                else {
                    not_updated_tasks[TaskStatus(i)] = 0;
                }*/
            }

            if ((x_p_s_i) >= task_count)
            {
                progress = task_count;                 //обновленные для i в сумме с пеершедшими
                not_progress = x_p_s_i - task_count;    //не обновленные для i
                not_updated_tasks[TaskStatus(i)] = not_progress;
              //  updated_tasks[TaskStatus(i)] = progress;
            }
            else {
                progress = x_p_s_i; //обновленные для i

                not_progress = 0;   //не обновленные для i
                
                // d = x_p_s_i;       //пеерходящие на i+1
                //updated_tasks[TaskStatus(i)] = progress;
                //progress = 0;
                not_updated_tasks[TaskStatus(i)] = not_progress;
                //updated_tasks[TaskStatus(i)] = progress;
                // progress = 0;
                task_count = task_count - x_p_s_i; // счетчик минус тройка

                 /*if (x_p_s_i - progress < 0)
                 {
                     not_progress = 0;
                 }
                 else {
                     not_progress = x_p_s_i - progress;
                 }
                 progress = x_p_s_i;*/
            }

        if (progress > 0 && i==2)
        {
            updated_tasks[TaskStatus::DONE] = progress;

            person_status_task_[person][TaskStatus::DONE] = progress;


            
           
            //not_updated_tasks[TaskStatus(i + 1)] = person_status_task_[person][TaskStatus::DONE]+ progress;
  
         //   not_updated_tasks[TaskStatus(i+1)] = updated_tasks[TaskStatus(i + 1)];
        }

        }
       // not_updated_tasks[TaskStatus(i + 1)] = person_status_task_[person][TaskStatus::DONE] + progress;


            person_status_task_[person][TaskStatus::NEW] = not_updated_tasks[TaskStatus::NEW] + updated_tasks[TaskStatus::NEW];
            person_status_task_[person][TaskStatus::IN_PROGRESS] = not_updated_tasks[TaskStatus::IN_PROGRESS] + updated_tasks[TaskStatus::IN_PROGRESS];
            person_status_task_[person][TaskStatus::TESTING] = not_updated_tasks[TaskStatus::TESTING] + updated_tasks[TaskStatus::TESTING];
           // person_status_task_[person][TaskStatus::DONE] = not_updated_tasks[TaskStatus::DONE] + updated_tasks[TaskStatus::DONE];
  
            //person_status_task_[person][TaskStatus::DONE]+progress;

            return tie(updated_tasks, not_updated_tasks);

            //----------------------------------------------------------------
           // vector< pair<TaskStatus, int> > status_summ_task = {};
             // map<TaskStatus, int> status_summ_task = GetPersonTasksInfo(person);
           // GetPersonTasksInfo(person);
           // TasksInfo[TaskStatus::NEW];
           // status_summ_task.push_back({ TaskStatus::NEW, TaskStatus:: });

           /*for (const auto& i : status_summ_task) {
                if (i.first == TaskStatus::NEW) {
                    person_status_task_[person].insert({ TaskStatus::NEW, i.second });
                }
                if (i.first == TaskStatus::IN_PROGRESS) {
                    person_status_task_[person].insert({ TaskStatus::IN_PROGRESS, i.second });
                }

                if (i.first == TaskStatus::TESTING) {
                    person_status_task_[person].insert({ TaskStatus::TESTING, i.second });
                }
                if (i.first == TaskStatus::DONE) {
                    person_status_task_[person].insert({ TaskStatus::DONE, i.second });
                }
            }*/

            //sort(status_summ_task.begin(), status_summ_task.end(), [](auto& lhs, auto& rhs) {
             //   return 0; });

            // sort(person_statys_task_[person].begin(), person_statys_task_[person].end(), [](auto lhs, auto rhs) {
             //    lhs});
        
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

/*int main() {
    TeamTasks tasks;
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

    TasksInfo updated_tasks, untouched_tasks;

   tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 8);
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


}*/
int main() {
    cout << endl << "Test sample" << endl << endl;
    TasksInfo updated_tasks, untouched_tasks;
    
    /*
    // Test sample: Passed
    TeamTasks tasks;
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
    */

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
   /*
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
    */

/*
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
    }*/
    
}
