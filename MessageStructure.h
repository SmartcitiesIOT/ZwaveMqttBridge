#ifndef MESSAGESTRUCTURE 
#define MESSAGESTRUCTURE
// -*- mode: c++ -*-
#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "json/json.h"
#include<mosquittopp.h>


class NodeInfoStructure {
	private:
		std::string NodeID;
		std::string NodeName;
		std::string ManufacturerName;
		std::string ProductName;	
	public:
		NodeInfoStructure();
		Json::Value SetJson(std::string NodeID_m,
		std::string NodeName_m,
		std::string ManufacturerName_m,
		std::string ProductName_m);
		Json::Value ToJson() const;
};

class ValueStructure {
	private:
		std::string ValueLabel;
		std::string ValueType;
		std::string ValueHelp;
		std::string ValueUnit;	
		std::string ValueMin;	
		std::string ValueMax;

	public:
		ValueStructure();
		Json::Value SetJson(std::string ValueLabel_m,
		std::string ValueType_m,
		std::string ValueHelp_m,
		std::string ValueUnit_m,
		std::string ValueMin_m,
		std::string ValueMax_m);
		void setJson(std::string const &name);
		Json::Value ToJson() const;
};
class JsonMQTTMessage : public mosqpp::mosquittopp
 {
	private:
		   //vector<Contact> contacts_;
		const char     *     host;
		const char    *     id;
       		const char    *     topic;
		 int                port;
		 int                keepalive;

		
	public:
		Json::Value Message;
		std::string JsonString;
		    JsonMQTTMessage(const char *id, const char * _topic, const char *host, int port);
			void on_connect(int rc);
			void on_subscribe();
			void MakeJsonString();
			void SendMessage(Json::Value Message);			
			/*
	        const vector<Contact>& contacts() const;
	        void JsonSave(const char* filename);
	        void JsonLoad(const char* filename);
	        void AddPerson(string const &name, string const &phone_number);
	        const vector<Contact>::iterator& begin();
	        const vector<Contact>::iterator& end();*/
};
#endif
