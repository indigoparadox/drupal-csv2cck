<?php
// This line is so VIM recognizes this as a PHP file:
// vim:ft=php:shiftwidth=3:tabstop=3:

function csv2cck_field_options_link_field_form( $form, &$form_state ) {
}


/* Return: array( 
 *    'safe_value', A printable version of the field.
 *    'raw_value', The value to store when creating the node with this field.
 */
function csv2cck_field_options_link_field_convert(
   $data, $field_info, $options
) {
   // TODO: Should we be able to handle things like titles/alt text/etc here?
   return array(
      'safe_value' => $data,
      'raw_value' => $data,
      'valid' => true,
   );
}

function csv2cck_field_options_link_field_attachment(
   $data_array, $field_info
) {
   // Build the branchy array that hangs off of $node->field[language][0].
   // TODO: Should we be able to handle things like titles/alt text/etc here?
   if( !empty( $data_array['raw_value'] ) ) {
      return array( 
         'url' => $data_array['raw_value'],
         'title' => null,
         'attributes' => array(),
      );
   } else {
      return array();
   }
}

