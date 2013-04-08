<?php
// This line is so VIM recognizes this as a PHP file:
// vim:ft=php:shiftwidth=3:tabstop=3:

function csv2cck_field_options_node_reference_form( $form, &$form_state ) {
   // Pick out the config data and create a blank form to work with.
   $csv2cck_data = $form['csv2cck_data'];
   $form = array();

   // Build a list of fields that can be referenced by the selected node type.
   $available_fields = array();
   foreach(
      $csv2cck_data['field_info']['settings']['referenceable_types'] as
      $type_key => $type_value
   ) {
      if( $type_key === $type_value ) {
         foreach(
            field_info_instances( 'node', $type_value ) as
            $field_key => $field_value
         ) {
            $available_fields[$field_key] = $field_value['label'];
         }
      }
   }

   $form['reference_field'] = array(
      '#type' => 'select',
      '#title' => t( 'Reference Field' ),
      '#description' => t( 'The selected field is a node reference. Please '.
         'select the field from the referred node type that should be used '.
         'to match it to this column.' ),
      '#options' => $available_fields,
   );

   return $form;
}

/* Return: array( 
 *    'safe_value', A printable version of the field.
 *    'raw_value', The value to store when creating the node with this field.
 */
function csv2cck_field_options_node_reference_convert( 
   $data, $field_info, $options
) {
   /*static $quit;
   if( !$quit ) {
      debug( $data, $field_info );
      debug( $field_info, $field_info );
      debug( $options, $field_info );
      $quit = 1;
   }*/

   $output = array( 'safe_value' => '', 'raw_value' => '', 'valid' => false );

   // Load all of the nodes of the types that this field can reference.
   foreach(
      $field_info['settings']['referenceable_types'] as
      $type_key => $type_value
   ) {
      if( $type_key === $type_value ) {
         $efquery = new EntityFieldQuery();
         $efresults = $efquery->entityCondition( 'entity_type', 'node' )
            ->propertyCondition( 'type', $type_key )
            ->fieldCondition( $options['reference_field'], 'value', $data, '=' )
            ->execute();

         if( !empty( $efresults ) ) {
            $node_ref = reset( $efresults['node'] );
            $node_ref = node_load( $node_ref->nid );

            $output['raw_value'] = $node_ref->nid;
            $output['safe_value'] =
               l( $node_ref->title, 'node/'.$node_ref->nid );
            $output['valid'] = true;
         }
      }
   }

   // Find the node with the field specified in options containing $data.
   return $output;
}

function csv2cck_field_options_node_reference_attachment( 
   $data_array, $field_info
) {
   // Build the branchy array that hangs off of $node->field[language][0].
   if( !empty( $data_array['raw_value'] ) ) {
      return array( 'nid' => $data_array['raw_value'] );
   } else {
      return array();
   }
}

