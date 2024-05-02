import random

class CustomerSupportChatbot:
    def __init__(self):
        self.greetings = ["Hi there! How can I assist you today?", "Hello! What can I help you with?", "Hey! How may I help you?"]
        self.responses = {
            "order status": "To check your order status, please provide your order number.",
            "payment issue": "For payment issues, please contact our billing department at billing@example.com.",
            "product information": "To learn more about our products, please visit our website at www.example.com/products.",
            "technical support": "For technical support, please visit our support page at www.example.com/support.",
            "general inquiry": "For general inquiries, you can reach out to us at info@example.com."
        }

    def respond_to_inquiry(self, inquiry):
        inquiry = inquiry.lower()
        for key, value in self.responses.items():
            if key in inquiry:
                return value
        return "I'm sorry, I couldn't understand your inquiry. Please provide more details or try a different question."

chatbot = CustomerSupportChatbot()
print(random.choice(chatbot.greetings))
while True:
    user_input = input("You: ")
    if user_input.lower() == 'exit':
        print("Goodbye! Have a great day!")
        break
    else:
        response = chatbot.respond_to_inquiry(user_input)
        print("Bot:",response)
