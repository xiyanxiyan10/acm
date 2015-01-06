import os

def file_count(dirname,filter_types=[]):
     '''Count the files in a directory includes its subfolder's files
        You can set the filter types to count specific types of file'''
     count=0
     filter_is_on = False
     if filter_types!=[]: filter_is_on=True
     for item in os.listdir(dirname):
         abs_item=os.path.join(dirname,item)
         #print item
         if os.path.isdir(abs_item):
             #Iteration for dir
             count+=file_count(abs_item,filter_types)
         elif os.path.isfile(abs_item):
             if filter_is_on:
                 #Get file's extension name
                 extname=os.path.splitext(abs_item)[1]
                 if extname in filter_types:
                     count+=1
             else:
                 count+=1
     return count

 file_count('./')
