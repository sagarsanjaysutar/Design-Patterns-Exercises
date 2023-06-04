#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <mutex>

using namespace std;

/**
 * \brief Singleton class
 */
class Database
{
public:
    static Database *GetInstance()
    {
        // Thread safe access
        std::lock_guard<std::mutex> lock(mtxLock);
        if (db == nullptr)
        {
            cout << "Database::GetInstance(): Making a new instance" << endl;
            db = new Database();
            return db;
        }
        else
        {
            cout << "Database::GetInstance(): Returning existing instance" << endl;
            return db;
        }
    }

    /**
     * \brief Deletes clones copies.
     */
    Database(Database &db) = delete;
    void operator=(const Database &db) = delete;

private:
    /**
     * Constructor and destructors are private as they
     * cannot be accessed directly by client code.
     * Clients need to use GetInstance()
     */
    Database()
    {
        cout << "Database::Database" << endl;
    }

    ~Database()
    {
        cout << "Database::~Database" << endl;
    }

    /**
     * Ensuring only one instance is created.
     */
    static Database *db;
    static std::mutex mtxLock;
};

/**
 * Defining static members outside the class
 */
Database *Database::db{nullptr};
std::mutex Database::mtxLock;

#endif