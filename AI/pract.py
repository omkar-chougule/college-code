class es:
    def __init__(self):
        self.kb={"conneerr":{"symp":["hii"],"sol":"get"}}

    def diag(self,symp):
        for iss, details in self.kb.items():
            if any(sim in symp for sim in details["symp"]):
                return iss, details["sol"]
        return "Unknown", "Unable to diagnose the issue based on provided symptoms."

def user():
    while True:
        try:
            sym=input("ener the beha")
            symp=eval(sym)
            if not isinstance(symp,list):
                return ValueError
            return symp
        except(NameError,ValueError,SyntaxError):
            print("invalid")



exp=es()
im=user()
iss,sym=exp.diag(im)
print("issue:",iss)
print("solution:",sym)