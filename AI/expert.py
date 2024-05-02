
class ExpertSystem:
    def __init__(self):
        self.knowledge_base = {
            "computer_wont_turn_on": {
                "symptoms": ["No lights", "No noise", "No response when pressing power button"],
                "solution": "Check power source, ensure power cable is connected, try different power outlet."
            },
            "computer_running_slow": {
                "symptoms": ["Programs take a long time to open", "Frequent freezing or crashing"],
                "solution": "Check for malware, close unnecessary programs running in the background, clear temporary files."
            },
            "no_internet_connection": {
                "symptoms": ["Unable to browse websites", "Network icon showing no connection"],
                "solution": "Check network cables, restart router, reset network settings."
            },
            "printer_not_printing": {
                "symptoms": ["Print job stuck in queue", "Printer not responding to print commands"],
                "solution": "Check printer connections, restart printer, reinstall printer drivers."
            },
            "software_crashing": {
                "symptoms": ["Frequent crashes when using a specific software"],
                "solution": "Update software to the latest version, check for compatibility issues."
            }
        }

    def diagnose_issue(self, symptoms):
        for issue, details in self.knowledge_base.items():
            if any(symptom in symptoms for symptom in details["symptoms"]):
                return issue, details["solution"]
        return "Unknown", "Unable to diagnose the issue based on provided symptoms."

# def get_user_symptoms():
#     user_input = input("Please enter the symptoms you are experiencing as a list (e.g., ['No lights', 'No noise']):").strip()
#     return eval(user_input)
def get_user_symptoms():
    while True:
        try:
            user_input = input("Please enter the symptoms you are experiencing as a list (e.g., ['No lights', 'No noise']): ").strip()
            symptoms = eval(user_input)
            if not isinstance(symptoms, list):
                raise ValueError
            return symptoms
        except (SyntaxError, NameError, ValueError):
            print("Invalid input. Please enter the symptoms as a list.")


expert_system = ExpertSystem()
user_symptoms = get_user_symptoms()
issue, solution = expert_system.diagnose_issue(user_symptoms)
print("Diagnosed Issue:", issue)
print("Solution:", solution)
