a = open('1.txt', 'w')
for i in range(32):
    a.writelines(str(7+i*8)+','+str(7+i*8+2)+','+str(7+i*8+4)+','+str(7+i*8+6)+'\n')
    a.writelines(str(7+i*8+3)+','+str(7+i*8+1)+','+str(7+i*8+7)+','+str(7+i*8+5)+'\n')