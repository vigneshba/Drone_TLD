function funcBW( message )
    
         global q;
         
         width = message.getWidth();
         height = message.getHeight();
         offset = message.getData().arrayOffset();
         indexR = offset+1:width*height+offset;
                 
         imgCol = typecast(message.getData().array(), 'uint8');
         imgdat = reshape(imgCol(indexR), width, height);
         
         imgdat2 = permute(imgdat, [2 1]);
         q=imgdat2;
         %imshow(imgdat2);
end
