#include "MessageStructure.h"
#include "mosquittopp.h"
#include <string>
using namespace std;
NodeInfoStructure::NodeInfoStructure()
{}
Json::Value NodeInfoStructure::SetJson( string NodeID_m,
		string NodeName_m,
		string ManufacturerName_m,
		string ProductName_m)
{
		Json::Value value(Json::objectValue);
		NodeID =  NodeID_m;
		NodeName = NodeName_m;
		ManufacturerName = ManufacturerName_m;
		ProductName = ProductName_m;
		cout<<" Product name debug::: "<<ProductName_m<<endl;
		return value;
}

ValueStructure::ValueStructure(){}

Json::Value ValueStructure::SetJson(string ValueLabel_m,
		string ValueType_m,
		string ValueHelp_m,
		string ValueUnit_m,
		string ValueMin_m,
		string ValueMax_m) {
	  Json::Value value(Json::objectValue);
	  value["ValueLabel"] = ValueLabel_m;
	  value["ValueType"] =  ValueType_m;
	  value["ValueHelp"] =  ValueHelp_m;
	  value["ValueUnits"] = ValueUnit_m;
	  value["ValueMin"] =   ValueMin_m;
	  value["ValueMax"] =   ValueMax_m;
	  return value;
}

JsonMQTTMessage::JsonMQTTMessage(const char * _id,const char * _topic, const char * _host, int _port) : mosquittopp(_id)
{
	mosqpp::lib_init();        // Mandatory initialization for mosquitto library
	this->keepalive = 60;    // Basic configuration setup for myMosq class
	this->id = _id;
	this->port = _port;
	this->host = _host;
	this->topic = _topic;
	connect_async(host,     // non blocking connection to broker request
	       port,
	       keepalive);
	loop_start();            // Start thread managing connection / publish / subscribe

}
void JsonMQTTMessage::on_connect(int rc){
		printf("Connected with code %d. \n", rc);

	if (rc == 0)
	{
		subscribe(NULL, "command/IGot");
	}
}
/*void JsonMQTTMessage::on_subscribe();
{

}*/
void JsonMQTTMessage::MakeJsonString()
{
	Json::StreamWriterBuilder builder;
	//builder["indentation"] = ""; // If you want whitespace-less output
	JsonString = Json::writeString(builder, Message);
}





