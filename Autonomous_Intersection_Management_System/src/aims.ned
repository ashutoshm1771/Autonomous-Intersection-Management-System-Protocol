//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package autonomous_intersection_management_system;

network application_layer
{
    @display("bgb=833,421");
    types:
        simple Core_Processor
        {
            gates:
                input input_gate_message;
                output output_gate_message;
                
                input input_gate_ocr;
                output output_gate_ocr;
                
                input input_gate_request;
                output output_gate_request;
                
                input input_gate_smart_city;
                output output_gate_smart_city;
        }
        simple Message_Processor
        {
            gates:
                input input_gate_core;
                output output_gate_core;
                
                input input_gate_agent;
                output output_gate_agent;
        }
        simple Video_Processor
        {
            gates:
                input input_gate_ocr;
                output output_gate_ocr;
        }
        simple OCR_Module
        {
            gates:
                input input_gate_core;
                output output_gate_core;
                
                input input_gate_video;
                output output_gate_video;
        }
        simple Request_Receptor_Module
        {
            gates:
                input input_gate_core;
                output output_gate_core;
                
                input input_gate_agent;
                output output_gate_agent;
        }
        simple Agent_with_IoT_Module
        {
            gates:
                input input_gate_request;
                output output_gate_request;
                
                input input_gate_message;
                output output_gate_message;
        }
        simple Smart_City_Management_System
        {
            gates:
                input input_gate_core;
                output output_gate_core;
        }

    submodules:
        Core: Core_Processor {
            @display("p=455,161");
        }
        Message: Message_Processor {
            @display("p=276,311");
        }
        VideoProcessor: Video_Processor {
            @display("p=629,311");
        }
        OCRModule: OCR_Module {
            @display("p=455,311");
        }
        Request_Receptor: Request_Receptor_Module {
            @display("p=113,167");
        }
        Agent_with_IoT: Agent_with_IoT_Module {
            @display("p=113,311");
        }
        SmartCity: Smart_City_Management_System {
            @display("p=455,34");
        }
    connections:
        Core.output_gate_message --> Message.input_gate_core;
        Message.output_gate_core --> Core.input_gate_message;

        Core.output_gate_ocr --> OCRModule.input_gate_core;
        OCRModule.output_gate_core --> Core.input_gate_ocr;

        OCRModule.output_gate_video --> VideoProcessor.input_gate_ocr;
        VideoProcessor.output_gate_ocr --> OCRModule.input_gate_video;

        Core.output_gate_request --> Request_Receptor.input_gate_core;
        Request_Receptor.output_gate_core --> Core.input_gate_request;

        Agent_with_IoT.output_gate_request --> Request_Receptor.input_gate_agent;
        Request_Receptor.output_gate_agent --> Agent_with_IoT.input_gate_request;

		Agent_with_IoT.output_gate_message --> Message.input_gate_agent;
        Message.output_gate_agent --> Agent_with_IoT.input_gate_message;

        Core.output_gate_smart_city --> SmartCity.input_gate_core;
        SmartCity.output_gate_core --> Core.input_gate_smart_city;
}
