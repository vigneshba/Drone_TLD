function functionrgb( message )
    
         global q;
         
         width = message.getWidth();
         height = message.getHeight();
         offset = message.getData().arrayOffset()
         indexR = offset+1:3:width*height*3+offset;
         
         indexG = indexR+1;
         indexB = indexG+1;
         
         imgCol = typecast(message.getData().array(), 'uint8');
         size(imgCol)
         imgdat = reshape([imgCol(indexR); imgCol(indexG); imgCol(indexB)], width, height, 3);
         
         imgdat2 = permute(imgdat, [2 1 3]);
         q=imgdat2;
         %imshow(imgdat2);
end
