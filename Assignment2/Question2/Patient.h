#pragma once
#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

using namespace std;

class Patient {
public:
    int patientID;
    string name;
    string severity;

    // Constructor
    Patient(int id, const string& patientName, const string& severityLevel)
        : patientID(id), name(patientName), severity(severityLevel) {}

    // Getter functions
    int getPatientID() const { return patientID; }
    string getName() const { return name; }
    string getSeverity() const { return severity; }

    // Setter functions
    void setPatientID(int id) { patientID = id; }
    void setName(const string& patientName) { name = patientName; }
    void setSeverity(const string& severityLevel) { severity = severityLevel; }
};

#endif // PATIENT_H
