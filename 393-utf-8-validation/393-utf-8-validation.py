from typing import List

class Solution:    
    def validUtf8(self, data: List[int]) -> bool:
        binary = []
        bytes1 = ["0"]
        bytes2 = ["110", "10"]
        bytes3 = ["1110", "10", "10"]
        bytes4 = ["11110", "10", "10", "10"]
        oldBinary = []
        
        for num in data:
            binary.append(str(format(num, "08b")))
            
        while(binary):
            oldBinary = binary
            
            if(len(binary) >= 4):
                if(bytes4[0] == binary[0][:5]):
                    if(bytes4[1] == binary[1][:2]):
                        if(bytes4[2] == binary[2][:2]):
                            if(bytes4[3] == binary[3][:2]):
                                binary = binary[4:]
            
            if(len(binary) >= 3):                
                if(bytes3[0] == binary[0][:4]):
                    if(bytes3[1] == binary[1][:2]):
                        if(bytes3[2] == binary[2][:2]):
                            binary = binary[3:]
            
            if(len(binary) >= 2):  
                if(bytes2[0] == binary[0][:3]):
                    if(bytes2[1] == binary[1][:2]):
                        binary = binary[2:]
            
            if(len(binary) >= 1):      
                if(bytes1[0] == binary[0][:1]):
                    binary = binary[1:]
            
            if(oldBinary == binary): break
            
        if(not binary): return True
        return False